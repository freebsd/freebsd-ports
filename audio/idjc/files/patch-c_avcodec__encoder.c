Removed in 0.8.17, see https://sourceforge.net/p/idjc/code/ci/7ca28dc311b4/

--- c/avcodec_encoder.c.orig	2016-02-27 13:24:52 UTC
+++ c/avcodec_encoder.c
@@ -34,6 +34,21 @@
 #ifndef HAVE_AV_FRAME_UNREF
 #define av_frame_unref avcodec_get_frame_defaults
 #endif
+#ifndef AV_INPUT_BUFFER_PADDING_SIZE
+#define AV_INPUT_BUFFER_PADDING_SIZE FF_INPUT_BUFFER_PADDING_SIZE
+#endif
+#ifndef AV_INPUT_BUFFER_MIN_SIZE
+#define AV_INPUT_BUFFER_MIN_SIZE FF_MIN_BUFFER_SIZE
+#endif
+#ifndef AV_CODEC_CAP_DELAY
+#define AV_CODEC_CAP_DELAY CODEC_CAP_DELAY
+#endif
+#ifndef AV_CODEC_CAP_SMALL_LAST_FRAME
+#define AV_CODEC_CAP_SMALL_LAST_FRAME CODEC_CAP_SMALL_LAST_FRAME
+#endif
+#ifndef AV_CODEC_CAP_VARIABLE_FRAME_SIZE
+#define AV_CODEC_CAP_VARIABLE_FRAME_SIZE CODEC_CAP_VARIABLE_FRAME_SIZE
+#endif
 
 #define BYTE_ALIGNMENT (8)
 
@@ -115,14 +130,14 @@ static void live_avcodec_encoder_main(struct encoder *
 
         // allocate the input buffer
         s->inbufsize = c->frame_size * c->channels * av_get_bytes_per_sample(c->sample_fmt);
-        if (posix_memalign((void *)&s->inbuf, BYTE_ALIGNMENT, s->inbufsize + FF_INPUT_BUFFER_PADDING_SIZE)) {
+        if (posix_memalign((void *)&s->inbuf, BYTE_ALIGNMENT, s->inbufsize + AV_INPUT_BUFFER_PADDING_SIZE)) {
             fprintf(stderr, "live_avcodec_encoder_main: malloc failure\n");
             goto bailout;
         }
-        memset(s->inbuf + s->inbufsize, '\0', FF_INPUT_BUFFER_PADDING_SIZE); 
+        memset(s->inbuf + s->inbufsize, '\0', AV_INPUT_BUFFER_PADDING_SIZE); 
         
         // allocate the output buffer
-        if (posix_memalign((void *)&s->avpkt.data, BYTE_ALIGNMENT, FF_MIN_BUFFER_SIZE)) {
+        if (posix_memalign((void *)&s->avpkt.data, BYTE_ALIGNMENT, AV_INPUT_BUFFER_MIN_SIZE)) {
             fprintf(stderr, "live_avcodec_encoder_main: malloc failure\n");  
             goto bailout;
         }
@@ -192,11 +207,11 @@ static void live_avcodec_encoder_main(struct encoder *
 
                 encoder_ip_data_free(id);
             } else {
-                memset(s->inbuf, '\0', FF_INPUT_BUFFER_PADDING_SIZE);
+                memset(s->inbuf, '\0', AV_INPUT_BUFFER_PADDING_SIZE);
                 s->pkt_flags |= PF_FINAL;
             }
 
-            if (final && (s->codec->capabilities | CODEC_CAP_DELAY)) {
+            if (final && (s->codec->capabilities | AV_CODEC_CAP_DELAY)) {
                 av_free(s->decoded_frame);
                 s->decoded_frame = NULL;
             } else {
@@ -209,9 +224,9 @@ static void live_avcodec_encoder_main(struct encoder *
                 }
             }
             
-            if (!final || s->codec->capabilities & (CODEC_CAP_DELAY | CODEC_CAP_VARIABLE_FRAME_SIZE | CODEC_CAP_SMALL_LAST_FRAME)) {
+            if (!final || s->codec->capabilities & (AV_CODEC_CAP_DELAY | AV_CODEC_CAP_VARIABLE_FRAME_SIZE | AV_CODEC_CAP_SMALL_LAST_FRAME)) {
                 // decode as much data is this encoder wants to
-                s->avpkt.size = FF_MIN_BUFFER_SIZE;
+                s->avpkt.size = AV_INPUT_BUFFER_MIN_SIZE;
                 if (avcodec_encode_audio2(c, &s->avpkt, s->decoded_frame, &got_packet) < 0) {
                     fprintf(stderr, "avcodec_encoder_main: encoding failed\n");
                     encoder->encoder_state = ES_STOPPING;
