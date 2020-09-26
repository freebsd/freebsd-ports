--- src/titlescreen.c.orig	2011-05-04 00:16:12 UTC
+++ src/titlescreen.c
@@ -41,16 +41,16 @@ SDL_Rect dstupdate[MAX_UPDATES];
 int numupdates = 0; // tracks how many blits to be done
 
 // Colors we use:
-SDL_Color black;
-SDL_Color gray;
-SDL_Color dark_blue;
-SDL_Color red;
-SDL_Color white;
-SDL_Color yellow;
-SDL_Color bright_green;
+extern SDL_Color black;
+extern SDL_Color gray;
+extern SDL_Color dark_blue;
+extern SDL_Color red;
+extern SDL_Color white;
+extern SDL_Color yellow;
+extern SDL_Color bright_green;
 
 // Type needed for trans_wipe():
-struct blit {
+extern struct blit {
     SDL_Surface *src;
     SDL_Rect *srcrect;
     SDL_Rect *dstrect;
