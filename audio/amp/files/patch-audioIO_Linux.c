--- audioIO_Linux.c.orig	Sat May 31 10:47:58 1997
+++ audioIO_Linux.c	Fri Aug 23 14:46:27 2002
@@ -21,12 +21,14 @@
 #ifdef HAVE_MACHINE_SOUNDCARD_H
 #include <machine/soundcard.h>
 #else
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 
 /* optimal fragment size */
 
+#ifndef OS_BSD
 int AUSIZ = 0;
+#endif
 
 /* declare these static to effectively isolate the audio device */
 
@@ -42,6 +44,9 @@
 void
 audioOpen(int frequency, int stereo, int volume)
 {
+#ifdef OS_BSD
+	int temp;
+#endif
 	int supportedMixers, play_format=AFMT_S16_LE;
 
 	if ((audio_fd = open ("/dev/dsp", O_WRONLY, 0)) == -1)
@@ -78,7 +83,12 @@
 	if (volume != -1)
 		audioSetVolume(volume);
 
+#ifdef OS_BSD
+	temp = AUSIZ;
+	if (ioctl(audio_fd, SNDCTL_DSP_GETBLKSIZE, &temp) == -1)
+#else
 	if (ioctl(audio_fd, SNDCTL_DSP_GETBLKSIZE, &AUSIZ) == -1)
+#endif
 		die("Unable to get fragment size\n");
 }
 
