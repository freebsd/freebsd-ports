--- 3d.h.orig	Wed Aug 13 06:27:16 2003
+++ 3d.h	Fri Sep 12 00:05:49 2003
@@ -80,7 +80,7 @@
 #include <GL/gl.h>
 #include <GL/glu.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <GL/glx.h>
 #endif
 
