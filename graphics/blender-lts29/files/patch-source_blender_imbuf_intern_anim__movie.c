--- source/blender/imbuf/intern/anim_movie.c.orig	2023-05-12 23:31:38 UTC
+++ source/blender/imbuf/intern/anim_movie.c
@@ -574,7 +574,7 @@ static int startffmpeg(struct anim *anim)
   avcodec_parameters_to_context(pCodecCtx, video_stream->codecpar);
   pCodecCtx->workaround_bugs = FF_BUG_AUTODETECT;
 
-  if (pCodec->capabilities & AV_CODEC_CAP_AUTO_THREADS) {
+  if (pCodec->capabilities & AV_CODEC_CAP_OTHER_THREADS) {
     pCodecCtx->thread_count = 0;
   }
   else {
