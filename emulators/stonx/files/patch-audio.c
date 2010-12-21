--- audio.c.orig	2004-08-15 16:07:55.000000000 +0200
+++ audio.c	2010-04-03 09:44:58.000000000 +0200
@@ -45,6 +45,9 @@
 #include <linux/sched.h>
 #include <linux/unistd.h>
 #endif
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#define SOUND_DEVICE "/dev/dsp"
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 /* NetBSD's Linux API emulation, require -lossaudio too */
 #include <soundcard.h>
