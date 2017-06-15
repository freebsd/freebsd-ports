--- src/sprite.cc.orig	2007-11-02 11:48:20 UTC
+++ src/sprite.cc
@@ -351,7 +351,7 @@ bool Sprite::Load(unsigned char *Buf,lon
     // Fabrique la surface
     Image[i]=SDL_CreateRGBSurface((Dim[i].bpp-3)*SDL_SRCALPHA,Dim[i].L,Dim[i].H,Dim[i].bpp*8,
 				  0xff,0xff00,0xff0000,0xff000000*(Dim[i].bpp-3));
-    if(Image[i]<=NULL) {
+    if(Image[i]==NULL) {
       cerr <<"Impossible de créer une Surface SDL!"<<endl;
       return false;
     }
@@ -485,7 +485,7 @@ bool Sprite::Nouveau(int Lx,int Ly)
   // Fabrique la surface
   Image[0]=SDL_CreateRGBSurface((Dim[0].bpp-3)*SDL_SRCALPHA,Dim[0].L,Dim[0].H,Dim[0].bpp*8,
 				0xff,0xff00,0xff0000,0xff000000*(Dim[0].bpp-3));
-  if(Image[0]<=NULL) {
+  if(Image[0]==NULL) {
     cerr <<"Impossible de créer une Surface SDL!"<<endl;
     return false;
   }
