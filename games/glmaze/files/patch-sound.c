--- sound.c.orig	Thu Jun  5 19:49:36 2003
+++ sound.c	Thu Jun  5 19:50:22 2003
@@ -18,7 +18,7 @@
 #include "maze.h"
 
 #ifdef SOUND
-#include <SDL/SDL_mixer.h>
+#include <SDL_mixer.h>
 Mix_Chunk *sound[5];
 Mix_Music *music; 
 #endif
