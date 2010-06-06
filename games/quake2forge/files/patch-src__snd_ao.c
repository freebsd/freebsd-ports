--- src/snd_ao.c.orig	2010-06-06 16:01:19.000000000 +0200
+++ src/snd_ao.c	2010-06-06 16:01:46.000000000 +0200
@@ -62,6 +62,7 @@ qboolean SNDDMA_Init(struct sndinfo * s)
 	}
     }
 
+    memset(&format, 0, sizeof(format));
     format.bits = si->dma->samplebits = si->bits->value;
     format.rate = si->dma->speed = 44100;
     format.channels = si->dma->channels = si->channels->value;
