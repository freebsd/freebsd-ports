--- ctlrender/exr_file.cc.orig	2014-06-03 01:11:24 UTC
+++ ctlrender/exr_file.cc
@@ -63,6 +63,8 @@
 #include <ImfChannelList.h>
 #include <Iex.h>
 
+#include <fstream>
+
 bool exr_read(const char *name, float scale, ctl::dpx::fb<float> *pixels,
               format_t *format) {
 	std::ifstream ins;
