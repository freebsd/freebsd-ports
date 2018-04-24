https://github.com/OpenImageIO/oiio/commit/810a0235837d

--- src/ffmpeg.imageio/ffmpeginput.cpp.orig	2017-08-31 04:36:04 UTC
+++ src/ffmpeg.imageio/ffmpeginput.cpp
@@ -124,6 +124,15 @@ inline int receive_frame(AVCodecContext *avctx, AVFram
 }
 #endif
 
+
+// Changes for ffmpeg 4.0
+#define USE_FFMPEG_4_0 (LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(58, 18, 100))
+
+#if USE_FFMPEG_4_0
+#  define CODEC_CAP_DELAY AV_CODEC_CAP_DELAY
+#endif
+
+
 #include <boost/thread/once.hpp>
 
 #include "OpenImageIO/imageio.h"
