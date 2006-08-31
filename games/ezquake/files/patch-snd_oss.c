--- snd_oss.c.orig	Mon Mar 20 10:51:28 2006
+++ snd_oss.c	Wed Aug 30 20:09:50 2006
@@ -27,7 +27,11 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <stdio.h>
 
 #include "quakedef.h"
@@ -78,13 +82,6 @@
 		return 0;
 	}
 
-    if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {   
-        perror("GETOSPACE");
-		Com_Printf ("Um, can't do GETOSPACE?\n");
-		close(audio_fd);
-		return 0;
-    }
-   
 	shm = &sn;
     shm->splitbuffer = 0;
 
@@ -125,19 +122,6 @@
     else 
 		shm->channels = 2;
 
-	shm->samples = info.fragstotal * info.fragsize / (shm->samplebits/8);
-	shm->submission_chunk = 1;
-
-	// memory map the dma buffer
-
-	shm->buffer = (byte *) mmap(NULL, info.fragstotal * info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
-	if (!shm->buffer) {
-		perror(snd_dev);
-		Com_Printf ("Could not mmap %s\n", snd_dev);
-		close(audio_fd);
-		return 0;
-	}
-
 	tmp = 0;
 	if (shm->channels == 2)
 		tmp = 1;
@@ -182,6 +166,26 @@
     } else {
 		perror(snd_dev);
 		Com_Printf ("%d-bit sound not supported.", shm->samplebits);
+		close(audio_fd);
+		return 0;
+	}
+
+    if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {   
+        perror("GETOSPACE");
+		Com_Printf ("Um, can't do GETOSPACE?\n");
+		close(audio_fd);
+		return 0;
+    }
+
+	shm->samples = info.fragstotal * info.fragsize / (shm->samplebits/8);
+	shm->submission_chunk = 1;
+
+	// memory map the dma buffer
+
+	shm->buffer = (byte *) mmap(NULL, info.fragstotal * info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
+	if (!shm->buffer) {
+		perror(snd_dev);
+		Com_Printf ("Could not mmap %s\n", snd_dev);
 		close(audio_fd);
 		return 0;
 	}
