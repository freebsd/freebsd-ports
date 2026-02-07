https://gitlab.com/AOMediaCodec/SVT-AV1/-/blob/v4.0.0/.gitlab/workflows/linux/0002-svt-av1-fix-aq_mode.patch

--- src/codec_svt.c.orig	2025-05-09 16:21:14 UTC
+++ src/codec_svt.c
@@ -162,7 +162,11 @@ static avifResult svtCodecEncodeImage(avifCodec * code
 #else
         svt_config->logical_processors = encoder->maxThreads;
 #endif
+#if SVT_AV1_CHECK_VERSION(4, 0, 0)
+        svt_config->aq_mode = 2;
+#else
         svt_config->enable_adaptive_quantization = 2;
+#endif
         // disable 2-pass
 #if SVT_AV1_CHECK_VERSION(0, 9, 0)
         svt_config->rc_stats_buffer = (SvtAv1FixedBuf) { NULL, 0 };
