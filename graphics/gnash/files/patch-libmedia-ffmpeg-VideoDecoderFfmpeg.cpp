--- libmedia/ffmpeg/VideoDecoderFfmpeg.cpp.orig	2016-07-21 12:25:09 UTC
+++ libmedia/ffmpeg/VideoDecoderFfmpeg.cpp
@@ -544,7 +544,9 @@ get_buffer(AVCodecContext* avctx, AVFram
     vaapi_set_surface(pic, surface);
 
     static unsigned int pic_num = 0;
+#if LIBAVCODEC_VERSION_MAJOR < 57
     pic->type = FF_BUFFER_TYPE_USER;
+#endif
 #if LIBAVCODEC_VERSION_MAJOR < 54
     // This field has been unused for longer but has been removed with
     // libavcodec 54.
