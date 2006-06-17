--- ./snd_sdl.c.orig	Sat Jun 10 12:08:13 2006
+++ ./snd_sdl.c	Sat Jun 10 12:08:13 2006
@@ -94,7 +94,7 @@
 	shm = &the_shm;
 	shm->splitbuffer = 0;
 	shm->samplebits = (obtained.format & 0xFF);
-        shm->speed = obtained.freq;
+        shm->speed = desired.freq;
         shm->channels = obtained.channels;
 	shm->samples = obtained.samples*shm->channels;
 	shm->samplepos = 0;
@@ -119,3 +119,12 @@
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
