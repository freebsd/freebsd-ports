--- src/objview.cpp.orig	2007-09-02 16:01:24.000000000 +0200
+++ src/objview.cpp	2007-09-02 16:02:00.000000000 +0200
@@ -73,7 +73,7 @@
 	exit( returnCode );
 }
 
-int initGL( GLvoid );
+int initGL();
 // function to reset our viewport after a window resize
 int resizeWindow( int width, int height )
 {
@@ -109,7 +109,7 @@
 
 
 // general OpenGL initialization function
-int initGL( GLvoid )
+int initGL()
 {
 	cout << "Initializing OpenGL" << endl;
 	// Enable smooth shading
@@ -158,7 +158,7 @@
 }
 
 // Here goes our drawing code
-int drawGLScene( GLvoid )
+int drawGLScene()
 {
 	// These are to calculate our fps
 	static GLint T0     = 0;
