--- src/clients/sdl-vis/sdl-vis.c	Mon Mar 27 11:34:45 2006
+++ src/clients/sdl-vis/sdl-vis.c.orig	Sat Apr  1 18:21:01 2006
@@ -27,8 +27,8 @@
 #define FFT_BITS 10
 #define FFT_LEN (1<<FFT_BITS)
 
-#include <SDL/SDL.h>
-#include <SDL/SDL_ttf.h>
+#include <SDL.h>
+#include <SDL_ttf.h>
 #include <glib.h>
 #include <math.h>
 #include <stdlib.h>
