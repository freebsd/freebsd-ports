--- base/TextureUtil.cpp.orig	2020-12-18 16:34:55 UTC
+++ base/TextureUtil.cpp
@@ -55,6 +55,7 @@ extern "C" {
 
 #if EM_USE_ALLEGRO
 #include <allegro.h>
+#include <GL/gl.h>
 BITMAP * backbuffer = NULL;
 ZBUFFER * zbuffer = NULL;
 #endif // EM_USE_ALLEGRO
@@ -339,9 +340,10 @@ int TextureUtil::genTexture( char const * const filena
                              EmTexture * const texture)
 {
   //cout<<"+ Texture::genTexture : "<<filename<<endl;
-  *texture = 0;
 
 #if EM_USE_SDL
+  *texture = 0;
+
   // Load Texture
   struct_image* image = 0;
 
