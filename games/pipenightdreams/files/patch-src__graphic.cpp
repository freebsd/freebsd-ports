--- ./src/graphic.cpp.orig	2002-01-17 20:56:29.000000000 +0100
+++ ./src/graphic.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -44,11 +44,11 @@
   if (pixels) free(pixels);
 }
 
-void Graphic::setAlpha(char value=OPAQUE){
+void Graphic::setAlpha(char value){
   SDL_SetAlpha(surface, SDL_SRCALPHA, value);
 }
 
-void Graphic::enableClipping(bool flag=true){
+void Graphic::enableClipping(bool flag){
 
   if (flag){
     SDL_Rect rect;
@@ -68,7 +68,7 @@
   clip_height=height;
 }
 
-void Graphic::flip(Axis a=HAxis){
+void Graphic::flip(Axis a){
   if (surface){
     if (SDL_MUSTLOCK(surface))
       if (SDL_LockSurface(surface)<0) return;
