--- base/TextureUtil.cpp.orig	Wed May 14 14:42:22 2003
+++ base/TextureUtil.cpp	Sun Jun  8 22:02:21 2003
@@ -58,6 +58,7 @@
 
 #if EM_USE_ALLEGRO
 #include <allegro.h>
+#include <GL/gl.h>
 BITMAP * backbuffer = NULL;
 ZBUFFER * zbuffer = NULL;
 #endif // EM_USE_ALLEGRO
@@ -92,7 +93,7 @@
   for ( i = m_hImageName.begin();
         i != m_hImageName.end();
         i++) { 
-    glDeleteTextures (1, (*i).first ); //is that correct ?
+    glDeleteTextures (1, (GLuint *) (*i).first ); //is that correct ?
     delete (*i).first ;  // (*i).first = 0; 
   }
   m_hImageName.erase ( m_hImageName.begin() , m_hImageName.end() );
