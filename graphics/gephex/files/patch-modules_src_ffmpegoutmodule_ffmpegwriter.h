--- modules/src/ffmpegoutmodule/ffmpegwriter.h.orig
+++ modules/src/ffmpegoutmodule/ffmpegwriter.h
@@ -23,7 +23,8 @@
 
 #include <iostream>
 #include <map>
-
+#include <string>
+
 #define EMULATE_INTTYPES
 #include "avformat.h"
 #include "avcodec.h"
