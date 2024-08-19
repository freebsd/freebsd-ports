--- source/blender/imbuf/intern/anim_movie.cc.orig	2024-08-18 04:16:01 UTC
+++ source/blender/imbuf/intern/anim_movie.cc
@@ -653,7 +653,7 @@ static void ffmpeg_decode_store_frame_pts(ImBufAnim *a
 {
   anim->cur_pts = av_get_pts_from_frame(anim->pFrame);
 
-  if (anim->pFrame->key_frame) {
+  if (av_get_cur_key_frame_pts(anim->pFrame)) {
     anim->cur_key_frame_pts = anim->cur_pts;
   }
 
@@ -1032,10 +1032,9 @@ static int ffmpeg_seek_to_key_frame(ImBufAnim *anim,
 
     AVFormatContext *format_ctx = anim->pFormatCtx;
 
-    if (format_ctx->iformat->read_seek2 || format_ctx->iformat->read_seek) {
-      ret = av_seek_frame(anim->pFormatCtx, anim->videoStream, seek_pos, AVSEEK_FLAG_BACKWARD);
-    }
-    else {
+    int ret = av_seek_frame(anim->pFormatCtx, anim->videoStream, seek_pos, AVSEEK_FLAG_BACKWARD);
+
+    if (ret < 0) {
       ret = ffmpeg_generic_seek_workaround(anim, &seek_pos, pts_to_search);
       av_log(anim->pFormatCtx,
              AV_LOG_DEBUG,

