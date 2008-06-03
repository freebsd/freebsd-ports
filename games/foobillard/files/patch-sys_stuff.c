--- src/sys_stuff.c.orig	2008-05-27 21:00:17.000000000 +1000
+++ src/sys_stuff.c	2008-05-27 21:00:25.000000000 +1000
@@ -7,8 +7,8 @@
 #ifndef USE_SDL
 #include <GL/glut.h>
 #else
-#include <SDL/SDL.h>
-#include <SDL/SDL_syswm.h>
+#include <SDL.h>
+#include <SDL_syswm.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
 #endif
