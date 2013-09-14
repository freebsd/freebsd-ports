--- src/Loader.cxx.orig	2013-09-14 02:26:08.849226279 +0400
+++ src/Loader.cxx	2013-09-14 02:26:47.256226887 +0400
@@ -24,6 +24,7 @@
 {
 #include <png.h>
 #include <jpeglib.h>
+#include <stdlib.h>
 }
 
 void JpgLoader::Load(const std::string& filename,RGB& target,int x,int y)
