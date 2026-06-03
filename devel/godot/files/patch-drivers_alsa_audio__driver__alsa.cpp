--- drivers/alsa/audio_driver_alsa.cpp.orig	2024-04-14 15:55:55 UTC
+++ drivers/alsa/audio_driver_alsa.cpp
@@ -232,7 +232,7 @@ void AudioDriverALSA::thread_func(void *p_udata) {
 				ad->lock();
 				ad->start_counting_ticks();
 			} else {
-				wrote = snd_pcm_recover(ad->pcm_handle, wrote, 0);
+				wrote = snd_pcm_recover(ad->pcm_handle, wrote, 1); // silence stdout
 				if (wrote < 0) {
 					ERR_PRINT("ALSA: Failed and can't recover: " + String(snd_strerror(wrote)));
 					ad->active.clear();
