--- src/graphic.cpp.orig	Sat Jan  1 14:51:18 2005
+++ src/graphic.cpp	Sat Jan  1 14:52:31 2005
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
