--- main.cpp.orig	2014-06-09 19:39:33.355708525 +0400
+++ main.cpp	2014-06-09 19:40:20.729705674 +0400
@@ -20,6 +20,9 @@
 #include "piece3dobject.h"
 #include "nether.h"
 
+#include "GL/gl.h"
+#include "GL/glut.h"
+
 /*                                              GLOBAL VARIABLES INITIALIZATION:                                                        */ 
 
 int SCREEN_X=640;
@@ -158,6 +161,8 @@
 	screen_sfc = initialization((fullscreen ? SDL_FULLSCREEN : 0));
 	if (screen_sfc==0) return 0;
 
+	glutInit(&argc, argv);
+
 	time=init_time=SDL_GetTicks();
 
 	while (!quit) {
