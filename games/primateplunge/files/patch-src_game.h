--- src/game.h.orig	2005-12-31 15:59:12 UTC
+++ src/game.h
@@ -125,7 +125,7 @@ typedef struct _soundSet {
 
 
 /* Glabals in main.c */
-SDL_Surface *mainScreen;
+extern SDL_Surface *mainScreen;
 
 /* Globals in game.c */
 extern world* currentWorld;
