--- include/ui/gtk/ffmpeg.h.orig	2010-03-07 20:50:22.000000000 +0100
+++ include/ui/gtk/ffmpeg.h	2013-12-15 16:45:59.000000000 +0100
@@ -28,7 +28,9 @@
 extern "C"
 {
 #define __STDC_CONSTANT_MACROS
+#include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
+#include <libavformat/avio.h>
 }
 
 #include "kc/system.h"
