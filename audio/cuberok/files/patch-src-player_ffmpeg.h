--- src/player_ffmpeg.h.orig	2009-07-10 14:14:03.000000000 +0800
+++ src/player_ffmpeg.h	2010-05-10 21:49:51.000000000 +0800
@@ -27,8 +27,8 @@
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
 #else
-#include <avcodec.h>
-#include <avformat.h>
+#include <ffmpeg/avcodec.h>
+#include <ffmpeg/avformat.h>
 #endif
 }
 
