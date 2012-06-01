--- kipi-plugins/rawconverter/rawdecodingiface.cpp.orig	2008-12-13 12:20:05.000000000 +0100
+++ kipi-plugins/rawconverter/rawdecodingiface.cpp	2012-05-09 12:36:43.000000000 +0200
@@ -299,7 +299,7 @@
             if (!ICCColorProfile.isEmpty())
             {
                 png_set_iCCP(png_ptr, info_ptr, "icc", PNG_COMPRESSION_TYPE_BASE, 
-                             ICCColorProfile.data(), ICCColorProfile.size());
+                             (const png_byte *)ICCColorProfile.data(), ICCColorProfile.size());
             }
 
             QString libpngver(PNG_HEADER_VERSION_STRING);
