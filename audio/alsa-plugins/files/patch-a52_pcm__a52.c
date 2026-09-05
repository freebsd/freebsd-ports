--- a52/pcm_a52.c.orig	2024-06-10 09:18:39 UTC
+++ a52/pcm_a52.c
@@ -1202,7 +1202,22 @@ SND_PCM_PLUGIN_DEFINE_FUNC(a52)
 	rec->io.flags = SND_PCM_IOPLUG_FLAG_BOUNDARY_WA;
 #endif
 #ifdef USE_AVCODEC_FRAME
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 13, 100)
+	{
+		const enum AVSampleFormat *sample_fmts = NULL;
+		err = avcodec_get_supported_config(NULL, rec->codec,
+						   AV_CODEC_CONFIG_SAMPLE_FORMAT,
+						   0, (const void **)&sample_fmts,
+						   NULL);
+		if (err < 0 || !sample_fmts) {
+			err = -EINVAL;
+			goto error;
+		}
+		rec->av_format = sample_fmts[0];
+	}
+#else
 	rec->av_format = rec->codec->sample_fmts[0];
+#endif
 	rec->is_planar = av_sample_fmt_is_planar(rec->av_format);
 #else
 	rec->av_format = AV_SAMPLE_FMT_S16;
