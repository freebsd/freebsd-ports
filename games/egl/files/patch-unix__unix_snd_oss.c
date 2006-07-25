--- unix/unix_snd_oss.c.orig	Mon Jul 24 13:47:59 2006
+++ unix/unix_snd_oss.c	Mon Jul 24 14:01:57 2006
@@ -29,7 +29,11 @@
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
@@ -152,6 +156,14 @@
 	else
 		snd_audioDMA.channels = 1;
 
+    rc = ioctl (oss_audioFD, SNDCTL_DSP_SPEED, &snd_audioDMA.speed);
+    if (rc < 0) {
+		perror (oss_curDevice);
+        Com_Printf (PRNT_ERROR, "Could not set %s speed to %d", oss_curDevice, snd_audioDMA.speed);
+		close (oss_audioFD);
+        return qFalse;
+    }
+
     if (snd_audioDMA.sampleBits == 16) {
         rc = AFMT_S16_LE;
         rc = ioctl (oss_audioFD, SNDCTL_DSP_SETFMT, &rc);
@@ -178,14 +190,6 @@
 		close (oss_audioFD);
 		return qFalse;
 	}
-
-    rc = ioctl (oss_audioFD, SNDCTL_DSP_SPEED, &snd_audioDMA.speed);
-    if (rc < 0) {
-		perror (oss_curDevice);
-        Com_Printf (PRNT_ERROR, "Could not set %s speed to %d", oss_curDevice, snd_audioDMA.speed);
-		close (oss_audioFD);
-        return qFalse;
-    }
 
     if (ioctl (oss_audioFD, SNDCTL_DSP_GETOSPACE, &info) == -1) {   
         perror ("GETOSPACE");
