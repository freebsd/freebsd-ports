--- ./base/TextureUtil.cpp.orig	Thu Nov 20 17:46:16 2003
+++ ./base/TextureUtil.cpp	Fri Dec 12 21:14:17 2003
@@ -54,6 +54,7 @@
 
 #if EM_USE_ALLEGRO
 #include <allegro.h>
+#include <GL/gl.h>
 BITMAP * backbuffer = NULL;
 ZBUFFER * zbuffer = NULL;
 #endif // EM_USE_ALLEGRO
@@ -333,9 +334,10 @@
                              EmTexture * const texture)
 {
   //cout<<"+ Texture::genTexture : "<<filename<<endl;
-  *texture = 0;
 
 #if EM_USE_SDL
+  *texture = 0;
+
   // Load Texture
   struct_image* image = 0;
 
