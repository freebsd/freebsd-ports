--- dabreceiver-V2/backend/mp2processor-ffmpeg.cpp.orig	2013-05-20 16:11:57 UTC
+++ dabreceiver-V2/backend/mp2processor-ffmpeg.cpp
@@ -46,7 +46,7 @@ int32_t	mp2sampleRate	(uint8_t *frame) {
 
 	avcodec_register_all	();
 	av_init_packet		(&avpkt);
-	codec		= avcodec_find_decoder (CODEC_ID_MP1);
+	codec		= avcodec_find_decoder (AV_CODEC_ID_MP1);
 	if (codec == NULL) {
 	   fprintf (stderr, "Codec not found\n");
 	   return;
@@ -63,7 +63,7 @@ int32_t	mp2sampleRate	(uint8_t *frame) {
 	   return;
 	}
 
-	decoded_frame	= avcodec_alloc_frame ();
+	decoded_frame	= av_frame_alloc ();
 	if (decoded_frame == NULL) {
 	   fprintf (stderr, "Could not allocate audioframe\n");
 	   return;
@@ -104,7 +104,7 @@ int32_t	got_frame;
 	   (void)fwrite (MP2frame, sizeof (uint8_t), MP2framebytes, mp2File);
 	   return;
 	}
-	avcodec_get_frame_defaults (decoded_frame);
+	av_frame_unref (decoded_frame);
 
 	avpkt. data	= MP2frame;
 	avpkt. size	= MP2framebytes + 20;
