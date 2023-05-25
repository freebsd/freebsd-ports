--- source/blender/imbuf/intern/indexer.c.orig	2023-05-25 22:43:31 UTC
+++ source/blender/imbuf/intern/indexer.c
@@ -527,7 +527,7 @@ static struct proxy_output_ctx *alloc_proxy_output_ffm
   rv->c->codec_type = AVMEDIA_TYPE_VIDEO;
   rv->c->codec_id = AV_CODEC_ID_H264;
 
-  rv->of->oformat->video_codec = rv->c->codec_id;
+  ((struct AVOutputFormat*)(rv->of->oformat))->video_codec = rv->c->codec_id;
   rv->codec = avcodec_find_encoder(rv->c->codec_id);
 
   if (!rv->codec) {
@@ -540,7 +540,7 @@ static struct proxy_output_ctx *alloc_proxy_output_ffm
     return NULL;
   }
 
-  avcodec_get_context_defaults3(rv->c, rv->codec);
+  //avcodec_get_context_defaults3(rv->c, rv->codec);
 
   rv->c->width = width;
   rv->c->height = height;
