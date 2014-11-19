--- simgear/canvas/ShivaVG/src/shDefs.h.orig	2014-10-28 09:45:41.492715364 +0100
+++ simgear/canvas/ShivaVG/src/shDefs.h	2014-10-28 09:54:06.791735417 +0100
@@ -156,7 +156,7 @@
 
 /* OpenGL headers */
 
-#if defined(VG_API_LINUX)
+#if defined(VG_API_LINUX) || defined(VG_API_FREEBSD)
     #include <GL/gl.h>
     #include <GL/glx.h>
 #elif defined(VG_API_MACOSX)
