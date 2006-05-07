--- snd_linux.c.orig	Fri Sep 10 12:22:32 2004
+++ snd_linux.c	Mon Dec  5 20:05:40 2005
@@ -25,7 +25,11 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <linux/soundcard.h>
+#endif
 #include <stdio.h>
 #include "quakedef.h"
 
@@ -74,7 +78,8 @@
 		close (audio_fd);
 		return 0;
 	}
-
+//QuDos-
+/*  //Moved later thx Quake3
 	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1)
 	{   
 		perror ("GETOSPACE");
@@ -82,7 +87,8 @@
 		close (audio_fd);
 		return 0;
 	}
-    
+*/   
+//-QuDos
 	shm = &sn;
 	shm->splitbuffer = 0;
 
@@ -125,7 +131,8 @@
 		shm->channels = 2;
 	else
 		shm->channels = 2;
-
+//QuDos-
+/* //Call mmap later thx Quake3 
 	shm->samples = info.fragstotal * info.fragsize / (shm->samplebits / 8);
 	shm->submission_chunk = 1;
 
@@ -138,6 +145,8 @@
 		close (audio_fd);
 		return 0;
 	}
+*/
+//-QuDos
 
 	tmp = 0;
 	if (shm->channels == 2)
@@ -196,6 +205,30 @@
 		close (audio_fd);
 		return 0;
 	}
+
+//QuDos-
+//Moved from above thx Quake3
+	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1)
+	{   
+		perror ("GETOSPACE");
+		Con_Printf ("Um, can't do GETOSPACE?\n");
+		close (audio_fd);
+		return 0;
+	}
+	shm->samples = info.fragstotal * info.fragsize / (shm->samplebits / 8);
+	shm->submission_chunk = 1;
+
+// memory map the dma buffer
+	shm->buffer = (unsigned char *)mmap (NULL, info.fragstotal * info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
+	if (!shm->buffer || shm->buffer == (unsigned char *)-1)
+	{
+		perror ("/dev/dsp");
+		Con_Printf ("Could not mmap /dev/dsp\n");
+		close (audio_fd);
+		return 0;
+	}
+//end Quake3 sound fix by calling mmap later
+//-QuDos
 
 // toggle the trigger & start her up
 	tmp = 0;
