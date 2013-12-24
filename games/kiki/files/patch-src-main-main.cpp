--- src/main/main.cpp.orig	2003-04-11 17:42:29.000000000 +0400
+++ src/main/main.cpp	2013-12-24 05:06:01.864511655 +0400
@@ -9,6 +9,7 @@
 #include <math.h>
 
 #include <SDL.h>
+#include <GL/glut.h>
 #include "KikiController.h"
 
 // __________________________________________________________________________________________________
@@ -19,6 +20,8 @@
     int width, height;
     SDL_Surface * screen;
 
+	glutInit(&argc, argv);
+
     // initialize SDL
     if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) < 0 ) // SDL_INIT_TIMER
     {
