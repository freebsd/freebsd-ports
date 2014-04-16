--- src/gfxoutputdrv/ffmpeglib.c.orig	2011-09-18 15:09:45.000000000 +0200
+++ src/gfxoutputdrv/ffmpeglib.c	2012-11-25 13:11:58.342198505 +0100
@@ -208,12 +208,11 @@ static int load_avformat(ffmpeglib_t *li
         GET_SYMBOL_AND_TEST_AVFORMAT(av_init_packet);
         GET_SYMBOL_AND_TEST_AVFORMAT(av_register_all);
         GET_SYMBOL_AND_TEST_AVFORMAT(av_new_stream);
-        GET_SYMBOL_AND_TEST_AVFORMAT(av_set_parameters);
-        GET_SYMBOL_AND_TEST_AVFORMAT(av_write_header);
+        GET_SYMBOL_AND_TEST_AVFORMAT(avformat_write_header);
         GET_SYMBOL_AND_TEST_AVFORMAT(av_write_frame);
         GET_SYMBOL_AND_TEST_AVFORMAT(av_write_trailer);
-        GET_SYMBOL_AND_TEST_AVFORMAT(url_fopen);
-        GET_SYMBOL_AND_TEST_AVFORMAT(url_fclose);
+        GET_SYMBOL_AND_TEST_AVFORMAT(avio_open);
+        GET_SYMBOL_AND_TEST_AVFORMAT(avio_close);
         GET_SYMBOL_AND_TEST_AVFORMAT(dump_format);
         GET_SYMBOL_AND_TEST_AVFORMAT(av_guess_format);
 #ifndef HAVE_FFMPEG_SWSCALE
@@ -240,12 +239,11 @@ static void free_avformat(ffmpeglib_t *l
     lib->p_av_init_packet = NULL;
     lib->p_av_register_all = NULL;
     lib->p_av_new_stream = NULL;
-    lib->p_av_set_parameters = NULL;
-    lib->p_av_write_header = NULL;
+    lib->p_avformat_write_header = NULL;
     lib->p_av_write_frame = NULL;
     lib->p_av_write_trailer = NULL;
-    lib->p_url_fopen = NULL;
-    lib->p_url_fclose = NULL;
+    lib->p_avio_open = NULL;
+    lib->p_avio_close = NULL;
     lib->p_dump_format = NULL;
     lib->p_av_guess_format = NULL;
 #ifndef HAVE_FFMPEG_SWSCALE
