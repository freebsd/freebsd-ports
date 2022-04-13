--- src/events.c.orig	2010-05-09 16:25:03 UTC
+++ src/events.c
@@ -38,7 +38,7 @@
 
 extern Board *board;
 extern Configuration *conf;
-SDL_Surface *screen;
+extern SDL_Surface *screen;
 Cube *speedy;			// currently accelerated cube
 
 
