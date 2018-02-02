Fix types passed to SDL_Rect structure (SDL 1.2)

--- src/MOGL/MOGL_PoliceTTF.h.orig	2018-02-01 22:04:52.124355000 +0100
+++ src/MOGL/MOGL_PoliceTTF.h	2018-02-01 22:06:25.875693000 +0100
@@ -42,10 +42,10 @@
     {
         GLuint TextureName;
         Uint16 carac;
-        unsigned int x1;
-        unsigned int y1;
-        unsigned int x2;
-        unsigned int y2;
+        Sint16 x1;
+        Sint16 y1;
+        int x2;
+        int y2;
     };
 
     struct MOGL_Struct_TextureCarac
@@ -141,7 +141,7 @@
     MOGL_Struct_Carac * _Caracteres;
     MOGL_Struct_Carac * (_Correspondance[256-32]);
 
-    unsigned int _LastTextureX, _LastTextureY;
+    Sint16 _LastTextureX, _LastTextureY;
     unsigned int maxHeightCarac;
     MOGL_Map_Carac _MapCarac;
     MOGL_Vector_TextureName _VectorTextureName;
