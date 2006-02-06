--- Loader.cxx.orig	Mon Feb  6 13:45:24 2006
+++ Loader.cxx	Mon Feb  6 13:45:04 2006
@@ -20,8 +20,10 @@
 
 #include "Loader.hxx"
 
+extern "C" {
 #include <png.h>
 #include <jpeglib.h>
+}
 
 void JpgLoader::Load(const std::string& filename,RGB& target,int x,int y)
 {
