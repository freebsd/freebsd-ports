--- intern/ffmpeg/ffmpeg_compat.h.orig	2013-05-09 10:51:58.000000000 +0200
+++ intern/ffmpeg/ffmpeg_compat.h	2013-05-09 10:53:27.000000000 +0200
@@ -179,14 +179,14 @@
 #define avformat_close_input(x) av_close_input_file(*(x))
 #endif
 
-#if ((LIBAVCODEC_VERSION_MAJOR < 53) || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR < 35))
-FFMPEG_INLINE
-int avcodec_open2(AVCodecContext *avctx, AVCodec *codec, AVDictionary **options)
-{
-	/* TODO: no options are taking into account */
-	return avcodec_open(avctx, codec);
-}
-#endif
+//#if ((LIBAVCODEC_VERSION_MAJOR < 53) || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR < 35))
+//FFMPEG_INLINE
+//int avcodec_open2(AVCodecContext *avctx, AVCodec *codec, AVDictionary **options)
+//{
+//	/* TODO: no options are taking into account */
+//	return avcodec_open(avctx, codec);
+//}
+//#endif
 
 #if ((LIBAVFORMAT_VERSION_MAJOR < 53) || (LIBAVFORMAT_VERSION_MAJOR == 53 && LIBAVFORMAT_VERSION_MINOR < 21))
 FFMPEG_INLINE
@@ -196,12 +196,12 @@
 	return av_new_stream(s, 0);
 }
 
-FFMPEG_INLINE
-int avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options)
-{
-	/* TODO: no options are taking into account */
-	return av_find_stream_info(ic);
-}
+//FFMPEG_INLINE
+//int avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options)
+//{
+//	/* TODO: no options are taking into account */
+//	return av_find_stream_info(ic);
+//}
 #endif
 
 #if ((LIBAVFORMAT_VERSION_MAJOR > 53) || ((LIBAVFORMAT_VERSION_MAJOR == 53) && (LIBAVFORMAT_VERSION_MINOR > 32)) || ((LIBAVFORMAT_VERSION_MAJOR == 53) && (LIBAVFORMAT_VERSION_MINOR == 24) && (LIBAVFORMAT_VERSION_MICRO >= 100)))
