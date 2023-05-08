--- src/md3view.cpp.orig	2006-04-18 22:26:16 UTC
+++ src/md3view.cpp
@@ -72,7 +72,7 @@ void quit( int returnCode )
 	exit( returnCode );
 }
 
-int initGL( GLvoid );
+int initGL();
 // function to reset our viewport after a window resize
 int resizeWindow( int width, int height )
 {
@@ -108,7 +108,7 @@ int resizeWindow( int width, int height )
 
 
 // general OpenGL initialization function
-int initGL( GLvoid )
+int initGL()
 {
 	cout << "Initializing OpenGL" << endl;
 	// Enable smooth shading
