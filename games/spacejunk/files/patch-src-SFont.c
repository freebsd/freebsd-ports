Clang compatibility
--- src/SFont.c.orig	2013-06-14 01:28:33.767289275 +0400
+++ src/SFont.c	2013-06-14 01:39:06.709113401 +0400
@@ -72,7 +72,7 @@
    return -1;
 }
 
-Uint32 searchFirstPixel(SDL_Surface* s,int* X,int* Y,int* MinY){
+void searchFirstPixel(SDL_Surface* s,int* X,int* Y,int* MinY){
     Uint32 bgpixel = GetPixel(s, 0, s->h-1);
 
     int x=0;
