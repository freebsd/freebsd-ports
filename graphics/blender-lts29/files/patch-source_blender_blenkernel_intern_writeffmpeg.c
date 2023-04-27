--- source/blender/blenkernel/intern/writeffmpeg.c.orig	2022-11-08 13:50:16 UTC
+++ source/blender/blenkernel/intern/writeffmpeg.c
@@ -855,7 +855,7 @@ static AVStream *alloc_video_stream(FFMpegContext *con
                                                             255);
   st->avg_frame_rate = av_inv_q(c->time_base);
 
-  if (codec->capabilities & AV_CODEC_CAP_AUTO_THREADS) {
+  if (codec->capabilities & AV_CODEC_CAP_OTHER_THREADS) {
     c->thread_count = 0;
   }
   else {
