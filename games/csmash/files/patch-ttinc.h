--- ttinc.h.orig	Sun Aug 10 18:55:00 2003
+++ ttinc.h	Mon Nov 24 02:13:01 2003
@@ -204,12 +204,12 @@
 #include <GL/gl.h>
 #include <GL/glu.h>
 
-#include <SDL/SDL.h>
-#include <SDL/SDL_image.h>
-#include <SDL/SDL_thread.h>
+#include <SDL.h>
+#include <SDL_image.h>
+#include <SDL_thread.h>
 
 #ifdef HAVE_LIBSDL_MIXER
-#include <SDL/SDL_mixer.h>
+#include <SDL_mixer.h>
 #endif
 
 #include <libintl.h>
