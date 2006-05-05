--- ./gl_local.h.orig	Thu May 19 17:56:13 2005
+++ ./gl_local.h	Sun Feb 26 11:23:56 2006
@@ -28,7 +28,7 @@
 #include <GL/glu.h>
 #include <math.h>
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 #ifndef GL_COLOR_INDEX8_EXT
 #define GL_COLOR_INDEX8_EXT GL_COLOR_INDEX
 #endif
