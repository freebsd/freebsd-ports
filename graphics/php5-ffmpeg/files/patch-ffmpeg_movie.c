--- ffmpeg_movie.c.orig	2014-07-23 17:57:31 UTC
+++ ffmpeg_movie.c
@@ -315,7 +315,7 @@ FFMPEG_PHP_CONSTRUCTOR(ffmpeg_movie, __construct)
     } 
 
     if (persistent) {
-        list_entry *le;
+	zend_rsrc_list_entry *le;
         /* resolve the fully-qualified path name to use as the hash key */
         fullpath = expand_filepath(filename, NULL TSRMLS_CC);
 
@@ -350,7 +350,7 @@ FFMPEG_PHP_CONSTRUCTOR(ffmpeg_movie, __construct)
             }
             
         } else { /* no existing persistant movie, create one */
-            list_entry new_le;
+	    zend_rsrc_list_entry new_le;
             ffmovie_ctx = _php_alloc_ffmovie_ctx(1);
 
             if (_php_open_movie_file(ffmovie_ctx, filename)) {
@@ -364,7 +364,7 @@ FFMPEG_PHP_CONSTRUCTOR(ffmpeg_movie, __construct)
             new_le.ptr = ffmovie_ctx;
 
             if (FAILURE == zend_hash_update(&EG(persistent_list), hashkey, 
-                        hashkey_length+1, (void *)&new_le, sizeof(list_entry),
+                        hashkey_length+1, (void *)&new_le, sizeof(zend_rsrc_list_entry),
                         NULL)) {
                 php_error_docref(NULL TSRMLS_CC, E_WARNING, 
                         "Failed to register persistent resource");
@@ -508,7 +508,7 @@ static AVCodecContext* _php_get_decoder_context(ff_mov
                     codec_id));
 
         if (!decoder) {
-            zend_error(E_ERROR, "Could not find decoder for %s", 
+            zend_error(E_WARNING, "Could not find decoder for %s", 
                     _php_get_filename(ffmovie_ctx));
             return NULL;
         }
@@ -964,17 +964,19 @@ static const char* _php_get_codec_name(ff_movie_contex
     /* Copied from libavcodec/utils.c::avcodec_string */
     if (p) {
         codec_name = p->name;
+/*
         if (decoder_ctx->codec_id == CODEC_ID_MP3) {
             if (decoder_ctx->sub_id == 2)
                 codec_name = "mp2";
             else if (decoder_ctx->sub_id == 1)
                 codec_name = "mp1";
         }
-    } else if (decoder_ctx->codec_id == CODEC_ID_MPEG2TS) {
+ */
+    } else if (decoder_ctx->codec_id == AV_CODEC_ID_MPEG2TS) {
         /* fake mpeg2 transport stream codec (currently not registered) */
         codec_name = "mpeg2ts";
-    } else if (decoder_ctx->codec_name[0] != '\0') {
-        codec_name = decoder_ctx->codec_name;
+    } else if (avcodec_get_name(decoder_ctx->codec_id)[0] != '\0') {
+        codec_name = avcodec_get_name(decoder_ctx->codec_id);
     } else {
         /* output avi tags */
         if (decoder_ctx->codec_type == AVMEDIA_TYPE_VIDEO) {
@@ -1223,7 +1225,7 @@ static AVFrame* _php_read_av_frame(ff_movie_context *f
         return NULL;
     }
 
-    frame = avcodec_alloc_frame();
+    frame = av_frame_alloc();
 
     /* read next frame */ 
     while (av_read_frame(ffmovie_ctx->fmt_ctx, &packet) >= 0) {
@@ -1353,7 +1355,7 @@ static int _php_get_ff_frame(ff_movie_context *ffmovie
         ff_frame->keyframe = is_keyframe;
         ff_frame->pts = pts;
         
-        ff_frame->av_frame = avcodec_alloc_frame();
+        ff_frame->av_frame = av_frame_alloc();
         avpicture_alloc((AVPicture*)ff_frame->av_frame, ff_frame->pixel_format,
             ff_frame->width, ff_frame->height);
  
