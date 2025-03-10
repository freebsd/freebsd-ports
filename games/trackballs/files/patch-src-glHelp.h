--- src/glHelp.h.orig	2022-12-23 18:52:49 UTC
+++ src/glHelp.h
@@ -27,7 +27,8 @@
 
 #include "general.h"
 
-typedef struct _TTF_Font TTF_Font;
+#include <SDL2/SDL_ttf.h>
+
 typedef struct SDL_Surface SDL_Surface;
 class Map;
 class Game;
