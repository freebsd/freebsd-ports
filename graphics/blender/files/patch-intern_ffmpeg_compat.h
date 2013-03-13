--- intern/ffmpeg/ffmpeg_compat.h.orig	2013-03-06 17:47:13.000000000 +0100
+++ intern/ffmpeg/ffmpeg_compat.h	2013-03-06 17:49:33.000000000 +0100
@@ -113,14 +113,14 @@
 #define avformat_close_input(x) av_close_input_file(*(x))
 #endif
 
-#if ((LIBAVCODEC_VERSION_MAJOR < 53) || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR < 35))
-static inline
-int avcodec_open2(AVCodecContext *avctx, AVCodec *codec, AVDictionary **options)
-{
-	/* TODO: no options are taking into account */
-	return avcodec_open(avctx, codec);
-}
-#endif
+// #if ((LIBAVCODEC_VERSION_MAJOR < 53) || (LIBAVCODEC_VERSION_MAJOR == 53 && LIBAVCODEC_VERSION_MINOR < 35))
+// static inline
+// int avcodec_open2(AVCodecContext *avctx, AVCodec *codec, AVDictionary **options)
+// {
+// 	/* TODO: no options are taking into account */
+// 	return avcodec_open(avctx, codec);
+// }
+// #endif
 
 #if ((LIBAVFORMAT_VERSION_MAJOR < 53) || (LIBAVFORMAT_VERSION_MAJOR == 53 && LIBAVFORMAT_VERSION_MINOR < 21))
 static inline
@@ -130,12 +130,12 @@
 	return av_new_stream(s, 0);
 }
 
-static inline
-int avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options)
-{
-	/* TODO: no options are taking into account */
-	return av_find_stream_info(ic);
-}
+// static inline
+// int avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options)
+// {
+// 	/* TODO: no options are taking into account */
+// 	return av_find_stream_info(ic);
+// }
 #endif
 
 #if ((LIBAVFORMAT_VERSION_MAJOR > 53) || ((LIBAVFORMAT_VERSION_MAJOR == 53) && (LIBAVFORMAT_VERSION_MINOR > 32)) || ((LIBAVFORMAT_VERSION_MAJOR == 53) && (LIBAVFORMAT_VERSION_MINOR == 24) && (LIBAVFORMAT_VERSION_MICRO >= 100)))
