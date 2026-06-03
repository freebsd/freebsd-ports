--- src/ou.cpp.orig	2000-06-04 21:29:29 UTC
+++ src/ou.cpp
@@ -560,6 +560,7 @@ int main(int argc, char *argv[])
 #else
 	glutReshapeFunc(Reshape);
 #endif
+	glutDisplayFunc(glutPostRedisplay);
 	glutMainLoop();
 	return 0;
 }
