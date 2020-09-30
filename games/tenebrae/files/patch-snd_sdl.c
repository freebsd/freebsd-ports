--- snd_sdl.c.orig	2020-09-30 11:25:10 UTC
+++ snd_sdl.c
@@ -94,7 +94,7 @@ qboolean SNDDMA_Init(void)
 	shm = &the_shm;
 	shm->splitbuffer = 0;
 	shm->samplebits = (obtained.format & 0xFF);
-        shm->speed = obtained.freq;
+        shm->speed = desired.freq;
         shm->channels = obtained.channels;
 	shm->samples = obtained.samples*shm->channels;
 	shm->samplepos = 0;
@@ -119,3 +119,12 @@ void SNDDMA_Shutdown(void)
 	}
 }
 
+/*
+==============
+SNDDMA_Submit
+Send sound to device if buffer isn't really the dma buffer
+===============
+*/
+void SNDDMA_Submit(void)
+{
+}
