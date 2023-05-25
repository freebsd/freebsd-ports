--- intern/ffmpeg/ffmpeg_compat.h.orig	2023-05-12 23:31:31 UTC
+++ intern/ffmpeg/ffmpeg_compat.h
@@ -20,7 +20,9 @@
 #ifndef __FFMPEG_COMPAT_H__
 #define __FFMPEG_COMPAT_H__
 
+#include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
+#define AV_CODEC_CAP_AUTO_THREADS        AV_CODEC_CAP_OTHER_THREADS
 
 /* Check if our ffmpeg is new enough, avoids user complaints.
  * Minimum supported version is currently 3.2.0 which mean the following library versions:
