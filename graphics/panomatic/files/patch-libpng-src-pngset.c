--- libpng/src/pngset.c.orig	2008-02-14 23:14:15.000000000 +0000
+++ libpng/src/pngset.c	2012-09-24 12:02:46.529117189 +0000
@@ -672,7 +672,7 @@
 #if defined(PNG_iCCP_SUPPORTED)
 void PNGAPI
 png_set_iCCP(png_structp png_ptr, png_infop info_ptr,
-             png_charp name, int compression_type,
+             png_const_charp name, int compression_type,
              png_charp profile, png_uint_32 proflen)
 {
    png_charp new_iccp_name;
