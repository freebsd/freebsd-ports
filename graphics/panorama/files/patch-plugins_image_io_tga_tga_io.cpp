--- plugins/image_io/tga/tga_io.cpp.orig	Thu Nov 21 01:54:18 2002
+++ plugins/image_io/tga/tga_io.cpp	Tue Feb  1 17:55:53 2005
@@ -156,11 +156,11 @@
   bAux = sFile.get();                             // Attributes 
   bAttributes = bAux;
 
-  sFile.seekg(sFile.tellg() + long(bIndentifierLength));
+  sFile.seekg(bIndentifierLength, std::ios::cur);
   
   if ( bColorMapType )                            // Ignore color map
   {
-    sFile.seekg (sFile.tellg() + long((bSizeofMapEntry / 8) * zCountColors));
+    sFile.seekg ((bSizeofMapEntry / 8) * zCountColors, std::ios::cur);
   }
 
   if ( bAttributes & 0x20 )                       // Check origin (upper or lower left)
