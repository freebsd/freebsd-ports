--- base/TextureUtil.cpp.orig	2018-03-24 23:40:31 UTC
+++ base/TextureUtil.cpp
@@ -54,6 +54,7 @@ extern "C" {
 
 #if EM_USE_ALLEGRO
 #include <allegro.h>
+#include <GL/gl.h>
 BITMAP * backbuffer = NULL;
 ZBUFFER * zbuffer = NULL;
 #endif // EM_USE_ALLEGRO
@@ -333,9 +334,10 @@ int TextureUtil::genTexture( char const * const filena
                              EmTexture * const texture)
 {
   //cout<<"+ Texture::genTexture : "<<filename<<endl;
-  *texture = 0;
 
 #if EM_USE_SDL
+  *texture = 0;
+
   // Load Texture
   struct_image* image = 0;
 
