--- src/sys_stuff.c.orig	Sat Nov 15 21:24:23 2003
+++ src/sys_stuff.c	Sat Nov 15 21:25:20 2003
@@ -5,7 +5,7 @@
 #ifndef USE_SDL
 #include <GL/glut.h>
 #else
-#include <SDL/SDL.h>
+#include <SDL.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
 #endif
