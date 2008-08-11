--- modules/src/ffmpegoutmodule/ffmpegwriter.h.orig	2007-04-29 23:53:40.000000000 +0900
+++ modules/src/ffmpegoutmodule/ffmpegwriter.h	2008-08-09 19:44:12.000000000 +0900
@@ -24,10 +24,16 @@
 #include <iostream>
 #include <map>
 
+#if defined _MSC_VER
 #define EMULATE_INTTYPES
+#endif
+
+extern "C"
+{
 #include "avformat.h"
 #include "avcodec.h"
 #include "avutil.h"
+}
 
 
 class FFMpegWriter
