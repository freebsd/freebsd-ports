--- sound.h.orig	2016-07-26 16:04:42 UTC
+++ sound.h
@@ -6,7 +6,6 @@
 	Project Page: http://atariarea.krap.pl/stymulator
 	
 	Original ST-Sound GPL library by Arnaud Carre (http://leonard.oxg.free.fr)
-	ALSA (Advanced Linux Sound Architecture) library (http://www.alsa-project.org/)
 
 -----------------------------------------------------------------------------
  *   STYMulator is free software; you can redistribute it and/or modify    *
@@ -28,8 +27,8 @@
 #ifndef SOUND_H
 #define SOUND_H
 
-#include <alsa/asoundlib.h>
+#include <sys/soundcard.h>
 
-int alsa_init(snd_pcm_t *pcm_handle, snd_pcm_hw_params_t *hwparams);
+int oss_init(int);
 
 #endif
