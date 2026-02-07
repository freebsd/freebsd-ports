--- linux/snd_linux.c.orig	Thu Dec 21 14:55:31 2006
+++ linux/snd_linux.c	Thu Dec 21 14:56:41 2006
@@ -6,7 +6,11 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <stdio.h>
 
 #include "../client/client.h"
@@ -82,14 +86,6 @@
 		return false;
 	}
 
-    if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
-    {   
-        perror("GETOSPACE");
-		Com_Printf("Um, can't do GETOSPACE?\n", LOG_CLIENT);
-		close(audio_fd);
-		return 0;
-    }
-    
 // set sample bits & speed
 
     dma.samplebits = (int)sndbits->value;
@@ -113,22 +109,6 @@
 	dma.channels = (int)sndchannels->value;
 	if (dma.channels < 1 || dma.channels > 2)
 		dma.channels = 2;
-	
-	dma.samples = info.fragstotal * info.fragsize / (dma.samplebits/8);
-	dma.submission_chunk = 1;
-
-// memory map the dma buffer
-
-	if (!dma.buffer)
-		dma.buffer = (unsigned char *) mmap(NULL, info.fragstotal
-			* info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
-	if (!dma.buffer)
-	{
-		perror(snddevice->string);
-		Com_Printf("Could not mmap %s\n", LOG_CLIENT, snddevice->string);
-		close(audio_fd);
-		return false;
-	}
 
 	tmp = 0;
 	if (dma.channels == 2)
@@ -183,6 +163,30 @@
 	{
 		perror(snddevice->string);
 		Com_Printf("%d-bit sound not supported.", LOG_CLIENT, dma.samplebits);
+		close(audio_fd);
+		return false;
+	}
+
+    if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
+    {   
+        perror("GETOSPACE");
+		Com_Printf("Um, can't do GETOSPACE?\n", LOG_CLIENT);
+		close(audio_fd);
+		return 0;
+    }
+    
+	dma.samples = info.fragstotal * info.fragsize / (dma.samplebits/8);
+	dma.submission_chunk = 1;
+
+// memory map the dma buffer
+
+	if (!dma.buffer)
+		dma.buffer = (unsigned char *) mmap(NULL, info.fragstotal
+			* info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
+	if (!dma.buffer)
+	{
+		perror(snddevice->string);
+		Com_Printf("Could not mmap %s\n", LOG_CLIENT, snddevice->string);
 		close(audio_fd);
 		return false;
 	}
