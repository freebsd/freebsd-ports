--- src/concentration.c.orig	2005-11-09 16:05:02 UTC
+++ src/concentration.c
@@ -202,7 +202,7 @@ char * helpText[] = {
 
 /*****************************************************
  ****************************************************/
-inline void drawText(char * str, SDL_Color color, int x, int y, TTF_Font * font)
+static inline void drawText(char * str, SDL_Color color, int x, int y, TTF_Font * font)
 {
 	static SDL_Rect dest;
 	
