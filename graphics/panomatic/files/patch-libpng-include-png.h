--- libpng/include/png.h.orig	2008-02-14 23:14:15.000000000 +0000
+++ libpng/include/png.h	2012-09-24 12:02:46.519169872 +0000
@@ -2302,7 +2302,7 @@
 
 #if defined(PNG_iCCP_SUPPORTED)
 extern PNG_EXPORT(void,png_set_iCCP) PNGARG((png_structp png_ptr,
-   png_infop info_ptr, png_charp name, int compression_type,
+   png_infop info_ptr, png_const_charp name, int compression_type,
    png_charp profile, png_uint_32 proflen));
    /* Note to maintainer: profile should be png_bytep */
 #endif
