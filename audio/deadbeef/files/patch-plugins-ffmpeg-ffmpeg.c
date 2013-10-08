--- plugins/ffmpeg/ffmpeg.c.orig	2013-10-08 19:54:33.943158658 -0300
+++ plugins/ffmpeg/ffmpeg.c	2013-10-08 19:54:44.352159132 -0300
@@ -25,20 +25,11 @@
 
 #include "../../deadbeef.h"
 
-#if !FFMPEG_OLD
-
 #include <libavformat/avformat.h>
 #include <libavcodec/avcodec.h>
 #include <libavutil/avutil.h>
 #include <libavutil/avstring.h>
 
-#else
-
-#include <ffmpeg/avformat.h>
-#include <ffmpeg/avcodec.h>
-#include <ffmpeg/avutil.h>
-#include <ffmpeg/avstring.h>
-
 #define AVERROR_EOF AVERROR(EPIPE)
 
 #if LIBAVFORMAT_VERSION_MAJOR < 53
@@ -49,8 +40,6 @@
 #define AV_VERSION_INT(a, b, c) (a<<16 | b<<8 | c)
 #endif
 
-#endif
-
 //#define trace(...) { fprintf(stderr, __VA_ARGS__); }
 #define trace(fmt,...)
 
