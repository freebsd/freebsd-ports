--- ./linux/snd_linux.c.orig	Tue May 23 20:05:59 2006
+++ ./linux/snd_linux.c	Tue May 23 20:06:00 2006
@@ -25,7 +25,11 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <stdio.h>
 
 #include "../client/snd_local.h"
@@ -56,7 +60,7 @@
 	extern uid_t saved_euid;
 
 	if (sndInitialized)
-		return;
+		return 1;
 
 	if (!snddevice) {
 		sndbits = Cvar_Register ("sndbits", "16", CVAR_ARCHIVE);
@@ -101,13 +105,6 @@
 		return 0;
 	}
 
-    if (ioctl (audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {   
-        perror ("GETOSPACE");
-		Com_Printf (0, "Um, can't do GETOSPACE?\n");
-		close (audio_fd);
-		return 0;
-    }
-
 	// set sample bits & speed
     snd_audioDMA.sampleBits = (int)sndbits->value;
 	if (snd_audioDMA.sampleBits != 16 && snd_audioDMA.sampleBits != 8) {
@@ -126,21 +123,6 @@
 	snd_audioDMA.channels = (int)sndchannels->value;
 	if ((snd_audioDMA.channels < 1) || (snd_audioDMA.channels > 2))
 		snd_audioDMA.channels = 2;
-	
-	snd_audioDMA.samples = info.fragstotal * info.fragsize / (snd_audioDMA.sampleBits/8);
-	snd_audioDMA.submissionChunk = 1;
-
-	// memory map the dma buffer
-	if (!snd_audioDMA.buffer)
-		snd_audioDMA.buffer = (unsigned char *) mmap(NULL, info.fragstotal
-			* info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
-
-	if (!snd_audioDMA.buffer) {
-		perror (snddevice->string);
-		Com_Printf (0, "Could not mmap %s\n", snddevice->string);
-		close (audio_fd);
-		return 0;
-	}
 
 	tmp = 0;
 	if (snd_audioDMA.channels == 2)
@@ -157,6 +139,14 @@
 	else
 		snd_audioDMA.channels = 1;
 
+    rc = ioctl (audio_fd, SNDCTL_DSP_SPEED, &snd_audioDMA.speed);
+    if (rc < 0) {
+		perror (snddevice->string);
+        Com_Printf (0, "Could not set %s speed to %d", snddevice->string, snd_audioDMA.speed);
+		close (audio_fd);
+        return 0;
+    }
+
     if (snd_audioDMA.sampleBits == 16) {
         rc = AFMT_S16_LE;
         rc = ioctl (audio_fd, SNDCTL_DSP_SETFMT, &rc);
@@ -182,13 +172,29 @@
 		return 0;
 	}
 
-    rc = ioctl (audio_fd, SNDCTL_DSP_SPEED, &snd_audioDMA.speed);
-    if (rc < 0) {
-		perror (snddevice->string);
-        Com_Printf (0, "Could not set %s speed to %d", snddevice->string, snd_audioDMA.speed);
+    if (ioctl (audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {   
+        perror ("GETOSPACE");
+		Com_Printf (0, "Um, can't do GETOSPACE?\n");
 		close (audio_fd);
-        return 0;
+		return 0;
     }
+
+	snd_audioDMA.samples = info.fragstotal * info.fragsize / (snd_audioDMA.sampleBits/8);
+	snd_audioDMA.submissionChunk = 1;
+
+	// memory map the dma buffer
+	if (!snd_audioDMA.buffer)
+		snd_audioDMA.buffer = (unsigned char *) mmap(NULL, info.fragstotal
+			* info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
+
+	if (!snd_audioDMA.buffer) {
+		perror (snddevice->string);
+		Com_Printf (0, "Could not mmap %s\n", snddevice->string);
+		close (audio_fd);
+		return 0;
+	}
+
+
 
 	// toggle the trigger & start her up
     tmp = 0;
