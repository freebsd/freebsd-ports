--- src/objview.cpp.orig	2006-04-18 20:34:25 UTC
+++ src/objview.cpp
@@ -73,7 +73,7 @@ void quit( int returnCode )
 	exit( returnCode );
 }
 
-int initGL( GLvoid );
+int initGL();
 // function to reset our viewport after a window resize
 int resizeWindow( int width, int height )
 {
@@ -109,7 +109,7 @@ int resizeWindow( int width, int height )
 
 
 // general OpenGL initialization function
-int initGL( GLvoid )
+int initGL()
 {
 	cout << "Initializing OpenGL" << endl;
 	// Enable smooth shading
@@ -158,7 +158,7 @@ int initGL( GLvoid )
 }
 
 // Here goes our drawing code
-int drawGLScene( GLvoid )
+int drawGLScene()
 {
 	// These are to calculate our fps
 	static GLint T0     = 0;
