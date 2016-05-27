--- src/glHelp.cc.orig	2007-04-07 13:15:09 UTC
+++ src/glHelp.cc
@@ -129,7 +129,6 @@ void drawSurface(SDL_Surface *surface,in
   // why is this removed? should it not be done???
   glDeleteTextures(1,&texture);  
 }
-inline Real abs(Real v) {return v>0.0?v:-v;}
 double mousePointerPhase=0.0;
 
 void tickMouse(Real td) {
