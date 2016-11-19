--- src/image_jpeg.c.orig	2007-11-26 20:47:43 UTC
+++ src/image_jpeg.c
@@ -92,10 +92,10 @@ probe_jpeg (AVFormatContext *ctx,
     return NULL;
 
   /* check for JPEG compliant codec */
-  if (codecs->vc->codec_id != CODEC_ID_MJPEG &&
-      codecs->vc->codec_id != CODEC_ID_MJPEGB &&
-      codecs->vc->codec_id != CODEC_ID_LJPEG &&
-      codecs->vc->codec_id != CODEC_ID_JPEGLS)
+  if (codecs->vc->codec_id != AV_CODEC_ID_MJPEG &&
+      codecs->vc->codec_id != AV_CODEC_ID_MJPEGB &&
+      codecs->vc->codec_id != AV_CODEC_ID_LJPEG &&
+      codecs->vc->codec_id != AV_CODEC_ID_JPEGLS)
     return NULL;
 
   for (i = 0; jpeg_profiles_mapping[i].profile; i++)
