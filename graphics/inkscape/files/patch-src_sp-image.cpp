--- src/sp-image.cpp.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/sp-image.cpp	2012-05-05 08:06:14.000000000 +0200
@@ -388,7 +388,7 @@
                 {
                     char* name = 0;
                     int compression_type = 0;
-                    char* profile = 0;
+                    png_byte * profile = 0;
                     png_uint_32 proflen = 0;
                     if ( png_get_iCCP(pngPtr, infoPtr, &name, &compression_type, &profile, &proflen) ) {
 //                                         g_message("Found an iCCP chunk named [%s] with %d bytes and comp %d", name, proflen, compression_type);
