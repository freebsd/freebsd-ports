--- src/vw/FileIO/PngIO.cc.orig	2011-05-13 01:00:56.000000000 +0200
+++ src/vw/FileIO/PngIO.cc	2012-05-06 13:36:44.000000000 +0200
@@ -9,6 +9,7 @@
 #include <vw/Core/Exception.h>
 #include <vw/Core/Log.h>
 #include <vw/Core/Settings.h>
+#include <zlib.h>
 
 static void png_error_handler(png_structp /*png_ptr*/, png_const_charp error_msg)
 {
