--- src/md3view.cpp.orig	2007-09-02 15:56:32.000000000 +0200
+++ src/md3view.cpp	2007-09-02 16:00:35.000000000 +0200
@@ -72,7 +72,7 @@
 	exit( returnCode );
 }
 
-int initGL( GLvoid );
+int initGL();
 // function to reset our viewport after a window resize
 int resizeWindow( int width, int height )
 {
@@ -108,7 +108,7 @@
 
 
 // general OpenGL initialization function
-int initGL( GLvoid )
+int initGL()
 {
 	cout << "Initializing OpenGL" << endl;
 	// Enable smooth shading
