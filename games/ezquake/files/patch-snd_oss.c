--- snd_oss.c.orig	Wed Nov 15 16:21:49 2006
+++ snd_oss.c	Tue Dec 19 19:26:57 2006
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
@@ -70,13 +74,6 @@
 		return 0;
 	}
 
-	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {
-		perror("GETOSPACE");
-		Com_Printf("Um, can't do GETOSPACE?\n");
-		close(audio_fd);
-		return 0;
-	}
-
 	// set sample bits & speed
 	shm->format.width  = (int) (s_bits.value / 8);
 	shm->format.speed = SND_Rate((int)s_khz.value);
@@ -127,6 +124,13 @@
 	} else {
 		perror(snd_dev);
 		Com_Printf("%d-bit sound not supported.", shm->format.width * 8);
+		close(audio_fd);
+		return 0;
+	}
+
+	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1) {
+		perror("GETOSPACE");
+		Com_Printf("Um, can't do GETOSPACE?\n");
 		close(audio_fd);
 		return 0;
 	}
