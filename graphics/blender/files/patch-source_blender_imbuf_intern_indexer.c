--- source/blender/imbuf/intern/indexer.c.orig	2022-11-04 00:33:07 UTC
+++ source/blender/imbuf/intern/indexer.c
@@ -559,7 +559,7 @@ static struct proxy_output_ctx *alloc_proxy_output_ffm
   av_dict_set(&codec_opts, "preset", "veryfast", 0);
   av_dict_set(&codec_opts, "tune", "fastdecode", 0);
 
-  if (rv->codec->capabilities & AV_CODEC_CAP_AUTO_THREADS) {
+  if (rv->codec->capabilities & AV_CODEC_CAP_OTHER_THREADS) {
     rv->c->thread_count = 0;
   }
   else {
@@ -872,7 +872,7 @@ static IndexBuildContext *index_ffmpeg_create_context(
   avcodec_parameters_to_context(context->iCodecCtx, context->iStream->codecpar);
   context->iCodecCtx->workaround_bugs = FF_BUG_AUTODETECT;
 
-  if (context->iCodec->capabilities & AV_CODEC_CAP_AUTO_THREADS) {
+  if (context->iCodec->capabilities & AV_CODEC_CAP_OTHER_THREADS) {
     context->iCodecCtx->thread_count = 0;
   }
   else {
