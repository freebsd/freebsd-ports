--- libmedia/ffmpeg/VideoDecoderFfmpeg.cpp.orig	2016-07-21 14:25:09.000000000 +0200
+++ libmedia/ffmpeg/VideoDecoderFfmpeg.cpp	2016-12-13 21:47:28.602555000 +0100
@@ -544,7 +544,9 @@
     vaapi_set_surface(pic, surface);
 
     static unsigned int pic_num = 0;
+#if LIBAVCODEC_VERSION_MAJOR < 57
     pic->type = FF_BUFFER_TYPE_USER;
+#endif
 #if LIBAVCODEC_VERSION_MAJOR < 54
     // This field has been unused for longer but has been removed with
     // libavcodec 54.
