--- src/unix/snd_oss.c.orig	Thu Sep 13 20:13:40 2007
+++ src/unix/snd_oss.c	Thu Sep 13 20:17:00 2007
@@ -25,12 +25,7 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
-#if defined(__FreeBSD__)
 #include <sys/soundcard.h>
-#endif
-#if defined(__linux__)
-#include <linux/soundcard.h>
-#endif
 #include <stdio.h>
 
 #include "../client/client.h"
@@ -43,7 +38,12 @@
 
 struct sndinfo * si;
 
-static int tryrates[] = { 48000, 44100, 22050, 11025, 8000 };
+static int tryrates[] = {
+	48000, 
+	44100,
+	22050,
+	11025
+};
 
 qboolean
 SNDDMA_Init(struct sndinfo * s) 
@@ -53,22 +53,22 @@
 	int		fmt;
 	int		tmp;
 	int		i;
-	struct audio_buf_info info;
+	struct		audio_buf_info info;
 	int		caps;
-	
+
 	if (snd_inited)
 		return 1;
 
 	snd_inited = 0;
 
 	si = s;
-	
+
+#if defined (__linux__)
 	if(!strcmp(si->snddevice->string, "default"))  //silly alsa default
 		si->snddevice->string = "/dev/dsp";
-
+#endif
 	/*
-	 * open /dev/dsp, confirm capability to mmap, and get size of dma
-	 * buffer
+	 * open /dev/dsp, confirm capability to mmap, and get size of dma buffer
 	 */
 	if (audio_fd == -1) {
 		audio_fd = open(si->snddevice->string, O_RDWR);
@@ -100,8 +100,8 @@
 		audio_fd = -1;
 		return 0;
 	}
-	/* set sample bits & speed */
-	
+
+	/* set sample bits & speed */	
 	si->dma->samplebits = (int)si->sndbits->value;
 	if (si->dma->samplebits != 16 && si->dma->samplebits != 8) {
         	ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
@@ -139,22 +139,11 @@
 	}
 
 	si->dma->speed = (int)si->sndspeed->value;
-
-	if (!si->dma->speed) {	
-		
-		if (si->s_khz->value == 48) {
-			si->dma->speed = 48000;
-		}
-		else if (si->s_khz->value == 44) {
-			si->dma->speed = 44100;
-		}
-		else if (si->s_khz->value == 22) {
-			si->dma->speed = 22050;
-		}
-		else  {
-			si->dma->speed = 11025;
-		}
-			si->dma->speed = 48000; /** Uhh **/
+	if (!si->dma->speed) {
+		if (si->s_khz->value == 48)      si->dma->speed = 48000;
+		else if (si->s_khz->value == 44) si->dma->speed = 44100;
+		else if (si->s_khz->value == 22) si->dma->speed = 22050;
+		else                             si->dma->speed = 11025;	
 	}
 	
 	if (!si->dma->speed) {
@@ -163,6 +152,7 @@
 				break;
 		si->dma->speed = tryrates[i];
 	}
+
 	si->dma->channels = (int)si->sndchannels->value;
 	if (si->dma->channels < 1 || si->dma->channels > 2)
 		si->dma->channels = 2;
@@ -177,8 +167,9 @@
 		               si->dma->channels);
 		close(audio_fd);
 		audio_fd = -1;
-        return 0;
+        	return 0;
 	}
+
 	if (tmp)
 		si->dma->channels = 2;
 	else
@@ -204,7 +195,6 @@
 	si->dma->submission_chunk = 1;
 
 	/* memory map the dma buffer */
-
 	if (!si->dma->buffer)
 		si->dma->buffer = (unsigned char *)mmap(NULL, info.fragstotal
 		         * info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
@@ -215,8 +205,8 @@
 		audio_fd = -1;
 		return 0;
 	}
-	/* toggle the trigger & start her up */
 
+	/* toggle the trigger & start her up */
 	tmp = 0;
 	rc = ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp);
 	if (rc < 0) {
@@ -235,12 +225,12 @@
 	    audio_fd = -1;
 	    return 0;
 	}
-
-
-	si->Com_Printf("\nInitializing OSS Sound System\n");
-	si->Com_Printf("Buffer size: %d\n", info.fragstotal * info.fragsize);
-
+	
 	si->dma->samplepos = 0;
+	
+	si->Com_Printf("Initializing OSS Sound System\n");
+	si->Com_Printf("Buffer size: %d\n", info.fragstotal * info.fragsize);
+	
 	snd_inited = 1;
 	return 1;
 }
@@ -262,11 +252,6 @@
 		return 0;
 	}
 
-	/*
-	 * dma.samplepos = (count.bytes / (dma.samplebits / 8)) &
-	 * (dma.samples-1);
-	 */
-	/* fprintf(stderr, "%d    \r", count.ptr); */
 	si->dma->samplepos = count.ptr / (si->dma->samplebits / 8);
 
 	return si->dma->samplepos;
@@ -286,7 +271,7 @@
 		snd_inited = 0;
 	}
 #else
-	printf ("SNDDMA_Shutdown\n");
+	si->Com_Printf("SNDDMA_Shutdown\n");
 	if (snd_inited) {
 		munmap (si->dma->buffer, si->dma->samples *si->dma->samplebits / 8);
 		si->dma->buffer = 0L;
