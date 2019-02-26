#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

// Write definition of inputMatrix(),matrixMultiply() and showMatrix() here
void inputMatrix(double a[][N]){	
	for(int i=0; i<N ;i++){
		cout << "Row " << i+1 << ":";

		for(int j=0;j<N;j++){
			cin >> a[i][j];	}
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]>=A[i][j+1] && A[i][j]>=A[i][j-1] && A[i][j]>=A[i+1][j] && A[i][j]>=A[i-1][j])
				B[i][j]=true; 	
			else B[i][j]=false;
		} 
		
	}

	for(int i=0;i<N;i++){
		B[0][i] = 0;
		B[4][i] = 0;
		B[i][0] = 0;
		B[i][4] = 0;
	}

}

void showMatrix(const bool B[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << B[i][j] << " " ;
		}
		cout << '\n';
	}
}