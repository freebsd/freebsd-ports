--- rplayd/audio/audio_FreeBSD.c.orig	Wed Mar 10 16:58:10 1999
+++ rplayd/audio/audio_FreeBSD.c	Thu Apr 11 07:45:56 2002
@@ -35,7 +35,7 @@
 #include <sys/ioctl.h>
 #include <sys/errno.h>
 #include <errno.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 
 /*
  * for the poor folks who don't have a sound card, but use the pc speaker
@@ -353,7 +353,7 @@
 	return (-1);
     }
 
-    if (!(mxdevmask & SOUND_MIXER_PCM))
+    if (!(mxdevmask & SOUND_MASK_PCM))
     {
 	report(REPORT_ERROR, "rplay_audio_get_volume: pcm mixer device not installed\n");
 	close(mx);
@@ -417,7 +417,7 @@
 	return (-1);
     }
 
-    if (!(mxdevmask & SOUND_MIXER_PCM))
+    if (!(mxdevmask & SOUND_MASK_PCM))
     {
 	report(REPORT_ERROR, "rplay_audio_set_volume: pcm mixer device not installed\n");
 	close(mx);
