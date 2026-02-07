--- src/io/source_avcodec.c.orig	2025-10-09 07:49:13 UTC
+++ src/io/source_avcodec.c
@@ -67,7 +67,7 @@
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(56, 56, 0)
 #define AUBIO_AVCODEC_MAX_BUFFER_SIZE FF_MIN_BUFFER_SIZE
 #else
-#define AUBIO_AVCODEC_MAX_BUFFER_SIZE AV_INPUT_BUFFER_MIN_SIZE
+#define AUBIO_AVCODEC_MAX_BUFFER_SIZE 16384
 #endif
 
 #if LIBAVCODEC_VERSION_MAJOR >= 59
@@ -345,8 +345,8 @@ void aubio_source_avcodec_reset_resampler(aubio_source
     av_channel_layout_default(&input_layout, s->input_channels);
     av_channel_layout_default(&output_layout, s->input_channels);
 
-    av_opt_set_chlayout(avr, "in_channel_layout",  &input_layout,        0);
-    av_opt_set_chlayout(avr, "out_channel_layout", &output_layout,       0);
+    av_opt_set_chlayout(avr, "in_chlayout",  &input_layout,        0);
+    av_opt_set_chlayout(avr, "out_chlayout", &output_layout,       0);
 #else
     int64_t input_layout = av_get_default_channel_layout(s->input_channels);
     int64_t output_layout = av_get_default_channel_layout(s->input_channels);
