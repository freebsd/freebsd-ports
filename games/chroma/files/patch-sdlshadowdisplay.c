--- sdlshadowdisplay.c.orig	2010-03-01 10:07:00.000000000 +0300
+++ sdlshadowdisplay.c	2013-06-04 03:08:27.120111885 +0400
@@ -88,7 +88,7 @@
 void displayshadowed_level(struct level* plevel);
 void displayshadowed_movers(struct level* plevel, int redraw);
 
-inline void displayshadowed_piece(struct level* plevel, int p, int x, int y, int d)
+static inline void displayshadowed_piece(struct level* plevel, int p, int x, int y, int d)
 {
     SDL_Surface *pimage;
 
@@ -255,7 +255,7 @@
     }
 }
 
-inline void displayshadowed_pieceshadow(struct level* plevel, int p, int x, int y, int d)
+static inline void displayshadowed_pieceshadow(struct level* plevel, int p, int x, int y, int d)
 {
     SDL_Surface *pimage;
 
@@ -310,7 +310,7 @@
     SDL_BlitSurface(pimage, &srect, screen_surface, &drect);
 }
 
-inline void displayshadowed_piecebase(struct level* plevel, int x, int y)
+static inline void displayshadowed_piecebase(struct level* plevel, int x, int y)
 {
     int p;
     SDL_Surface *pimage;
@@ -1063,7 +1063,7 @@
     }
 }
 
-inline void displayshadowed_redrawpiece(int p, int x, int y, int d)
+static inline void displayshadowed_redrawpiece(int p, int x, int y, int d)
 {
     int dx, dy;
 
@@ -1111,7 +1111,7 @@
     screen_redraw(0, 0, screen_width, screen_height);
 }
 
-inline int displayshadowed_count(struct level* plevel, int x, int y, int delta)
+static inline int displayshadowed_count(struct level* plevel, int x, int y, int delta)
 {
     unsigned int d;
 
