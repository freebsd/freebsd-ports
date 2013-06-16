--- src/concentration.c.orig	2005-11-09 19:05:02.000000000 +0300
+++ src/concentration.c	2013-06-04 07:00:25.084319599 +0400
@@ -202,7 +202,7 @@
 
 /*****************************************************
  ****************************************************/
-inline void drawText(char * str, SDL_Color color, int x, int y, TTF_Font * font)
+static inline void drawText(char * str, SDL_Color color, int x, int y, TTF_Font * font)
 {
 	static SDL_Rect dest;
 	
