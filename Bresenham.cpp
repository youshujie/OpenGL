// Bresenham.cpp : 定义控制台应用程序的入口点。
#include "StdAfx.h"
#include <gl/glut.h>  

void Init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);//定义二维图像投影矩阵
}

void drawpiexel(int x0,int y0, int x1, int y1) {
	int x, y, dx, dy; 
	float k, e;
	dx = x1 - x0;
	dy = y1 - y0;
	k = dy / dx;
	e = -0.5;
	x = x0;
	y = y0;
	for ( int i = 0; i <= dx; i++) {
		glPointSize(1);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
		x++;
		e = e + k;
		if (e >= 0) {
			y++;
			e = e - 1;
		}
	}

}
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); //绘图颜色
	drawpiexel(10, 0, 80,100);
	glFlush();
}

int main(int argc, char * argv[] ) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);  
	glutInitWindowPosition(200,200);  
	glutCreateWindow(argv[0]);
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}