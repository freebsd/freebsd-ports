-- Fix build against FFmpeg 9.x where AVCodec.supported_framerates was removed.
-- Skip the supported-framerate adjustment when building against libavcodec
-- 63 or newer.

--- opencv/modules/videoio/src/cap_ffmpeg_impl.hpp.orig	2025-07-04 16:37:46 UTC
+++ opencv/modules/videoio/src/cap_ffmpeg_impl.hpp
@@ -2627,6 +2627,7 @@
     c->time_base.den = frame_rate;
     c->time_base.num = frame_rate_base;
     /* adjust time base for supported framerates */
+#if LIBAVCODEC_VERSION_MAJOR < 63
     if(codec && codec->supported_framerates){
         const AVRational *p= codec->supported_framerates;
         AVRational req = {frame_rate, frame_rate_base};
@@ -2644,6 +2645,7 @@
             return NULL;
         }
         c->time_base.den= best->num;
         c->time_base.num= best->den;
     }
+#endif

     c->gop_size = 12; /* emit one intra frame every twelve frames at most */
