--- ./ref_gl/gl_local.h.orig	Mon Apr 24 14:23:20 2006
+++ ./ref_gl/gl_local.h	Wed May 17 22:29:52 2006
@@ -28,7 +28,7 @@
 #include <GL/glu.h>
 #include <math.h>
 
-#ifndef __linux__
+#ifndef __unix__
 #ifndef GL_COLOR_INDEX8_EXT
 #define GL_COLOR_INDEX8_EXT GL_COLOR_INDEX
 #endif
