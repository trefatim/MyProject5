#include <iostream>

using namespace std;


/** \brief aлгоритм Дейкстры
 *
 * \param [in] a - матрица смежности
 * \param [in] n - количество вершин
 * \param [in] st - стартовая вершина
*/
void Dijkstra(int **a, const int n, int st) {
	int *distance, count, index, i, u, m=st+1;
	distance = new int [n];
	bool *visited = new bool [n];
	for (i = 0; i < n; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < n-1; count++) {
		int min = INT_MAX;
		for (i = 0; i < n; i++)
			if (!visited[i] && distance[i] <= min) {
				min = distance[i];
				index = i;
			}
			u = index;
			visited[u] = true;
			for (i = 0; i < n; i++)
				if (!visited[i] && a[u][i] && distance[u] != INT_MAX &&
					distance[u] + a[u][i] < distance[i])
					distance[i] = distance[u] + a[u][i];
	}
	for (i = 0; i < n; i++)
		if (distance[i] != INT_MAX)
			cout << m << " > " << i+1 << " = " << distance[i] << endl;
		else
			cout << m << " > " << i+1 << " = " << "way is closed" << endl;
}

/** \brief главная функция
 */
int main() {
	int n, **a;
	cin >> n;
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int [n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	Dijkstra(a, n, 0);
	system("pause");
	return 0;
}