--- src/sys_stuff.c.orig	Sat Oct 26 20:47:23 2002
+++ src/sys_stuff.c	Sat Oct 26 20:47:32 2002
@@ -5,7 +5,7 @@
 #ifndef USE_SDL
 #include <GL/glut.h>
 #else
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
 #endif
