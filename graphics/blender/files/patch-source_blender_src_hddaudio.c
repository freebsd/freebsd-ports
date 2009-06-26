--- source/blender/src/hddaudio.c.orig	2009-06-16 14:57:14.000000000 +0200
+++ source/blender/src/hddaudio.c	2009-06-24 08:34:40.000000000 +0200
@@ -282,11 +282,9 @@
 		hdaudio->resampler = 0;
 	}
 	if (!hdaudio->resampler) {
-		hdaudio->resampler = av_audio_resample_init(
+		hdaudio->resampler = audio_resample_init(
 			target_channels, hdaudio->channels,
-			target_rate, hdaudio->sample_rate,
-			SAMPLE_FMT_S16, SAMPLE_FMT_S16,
-			16, 10, 0, 0.8);
+			target_rate, hdaudio->sample_rate);
 		hdaudio->target_rate = target_rate;
 		hdaudio->target_channels = target_channels;
 		if (hdaudio->resample_cache) {
