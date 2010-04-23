--- ./sound.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./sound.cpp	2010-04-23 13:49:47.000000000 +0200
@@ -6,7 +6,6 @@
 	Project Page: http://atariarea.krap.pl/stymulator
 	
 	Original ST-Sound GPL library by Arnaud Carre (http://leonard.oxg.free.fr)
-	ALSA (Advanced Linux Sound Architecture) library (http://www.alsa-project.org/)
 
 -----------------------------------------------------------------------------
  *   STYMulator is free software; you can redistribute it and/or modify    *
@@ -25,73 +24,38 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ---------------------------------------------------------------------------*/
 
+#include <stdio.h>
+#include <unistd.h>
+#include <fcntl.h>
 #include "sound.h"
 
-snd_pcm_format_t format = SND_PCM_FORMAT_S16;
+int format = AFMT_S16_LE;
 
 int err, dir;
 int resample = 1;
 unsigned int rate = 44100;
 unsigned int channels = 1;
-unsigned int buffer_time = 500000;
 unsigned int period_time = 100000;
 
-snd_pcm_uframes_t buffer_size; //22050
-snd_pcm_uframes_t period_size; //4410
+int period_size; //4410
 
-int alsa_init(snd_pcm_t *pcm_handle, snd_pcm_hw_params_t *hwparams)
-{
-	if ((err = snd_pcm_hw_params_any(pcm_handle, hwparams)) < 0) {
-		printf("Broken configuration for playback: no configurations available: %s\n", snd_strerror(err));
-		return err;
-	}
-/*	removed snd_pcm_hw_params_set_rate_resample function that has been added to alsa-lib since 1.0.9rc2 (more portability)
-	
-	if ((err = snd_pcm_hw_params_set_rate_resample(pcm_handle, hwparams, resample)) < 0) {
-               	printf("Resampling setup failed for playback: %s\n", snd_strerror(err));
-               	return err;
-        }
-*/
-	if ((err = snd_pcm_hw_params_set_access(pcm_handle, hwparams, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
-		printf("Access type not available for playback: %s\n", snd_strerror(err));
-		return err;
-	}
-	if ((err = snd_pcm_hw_params_set_format(pcm_handle, hwparams, format)) < 0) {
-		printf("Sample format not available for playback: %s\n", snd_strerror(err));
-		return err;
-	}
-	if ((err = snd_pcm_hw_params_set_channels(pcm_handle, hwparams, channels)) < 0) {
-		printf("Channels count (%i) not available for playbacks: %s\n", channels, snd_strerror(err));
-		return err;
-	}
-	unsigned int rrate = rate;
-	if ((err = snd_pcm_hw_params_set_rate_near(pcm_handle, hwparams, &rrate, 0)) < 0) {
-		printf("Rate %iHz not available for playback: %s\n", rate, snd_strerror(err));
-		return err;
-	}
-	if (rrate != rate) {
-		printf("Rate doesn't match (requested %iHz, get %iHz)\n", rate, err);
-		return -EINVAL;
-	}
-	if ((err = snd_pcm_hw_params_set_buffer_time_near(pcm_handle, hwparams, &buffer_time, &dir)) < 0) {
-		printf("Unable to set buffer time %i for playback: %s\n", buffer_time, snd_strerror(err));
-		return err;
-	}
-	if ((err = snd_pcm_hw_params_get_buffer_size(hwparams, &buffer_size)) < 0) {
-		printf("Unable to get buffer size for playback: %s\n", snd_strerror(err));
-		return err;
-	}
-	if ((err = snd_pcm_hw_params_set_period_time_near(pcm_handle, hwparams, &period_time, &dir)) < 0) {
-		printf("Unable to set period time %i for playback: %s\n", period_time, snd_strerror(err));
-               	return err;
-	}
-        if ((err = snd_pcm_hw_params_get_period_size(hwparams, &period_size, &dir)) < 0) {
-		printf("Unable to get period size for playback: %s\n", snd_strerror(err));
-               	return err;
-        }
-	if ((err = snd_pcm_hw_params(pcm_handle, hwparams)) < 0) {
-		printf("Unable to set hw params for playback: %s\n", snd_strerror(err));
-		return err;
-        }
-	return 0;
+int oss_init(int audio_fd) {
+    period_size = 4096;
+    
+    if (ioctl(audio_fd, SNDCTL_DSP_SETFMT, &format) < 0) {
+        printf("Cannot set sample format\n");
+        return -1;
+    }
+    
+    if (ioctl(audio_fd, SNDCTL_DSP_CHANNELS, &channels) < 0) {
+        printf("Cannot set audio channels\n");
+        return -1;
+    }
+
+    if (ioctl(audio_fd, SNDCTL_DSP_SPEED, &rate) < 0) {
+        printf("Cannot set sample rate\n");
+        return -1;
+    }
+
+    return 0;
 }
