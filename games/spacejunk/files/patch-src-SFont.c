Clang compatibility
--- src/SFont.c.orig	2009-06-17 17:47:07 UTC
+++ src/SFont.c
@@ -72,7 +72,7 @@ static Uint32 GetPixel(SDL_Surface *Surf
    return -1;
 }
 
-Uint32 searchFirstPixel(SDL_Surface* s,int* X,int* Y,int* MinY){
+void searchFirstPixel(SDL_Surface* s,int* X,int* Y,int* MinY){
     Uint32 bgpixel = GetPixel(s, 0, s->h-1);
 
     int x=0;
