--- src/audio_out/audio_oss_out.c.old	Tue Jan 15 21:55:15 2002
+++ src/audio_out/audio_oss_out.c	Thu Apr 11 13:27:47 2002
@@ -49,7 +49,11 @@
 #if defined(__OpenBSD__)
 #include <soundcard.h>
 #elif defined(__FreeBSD__)
+#if __FreeBSD__ > 3
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h>
+#endif
 #else
 #if defined(__linux__)
 #include <linux/config.h> /* Check for DEVFS */
