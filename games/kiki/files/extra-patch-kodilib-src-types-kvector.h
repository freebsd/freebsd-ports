--- kodilib/src/types/KVector.h.orig	Mon Mar  6 12:42:24 2006
+++ kodilib/src/types/KVector.h	Mon Mar  6 12:42:32 2006
@@ -12,10 +12,7 @@
 #if defined(__APPLE__) && defined(__MACH__)
 #include <OpenGL/gl.h>
 #else
-#ifdef WIN32
 #define rint(x) (((x) < 0.0) ? (double)(int)((x) - 0.5) : (double)(int)((x) + 0.5))
-#include <GLUT/glut.h>
-#endif
 #include <GL/gl.h>
 #endif
 
