--- lib-src/portaudio/pa_unix_oss/pa_unix_oss.c.orig	Tue Dec  2 19:57:13 2003
+++ lib-src/portaudio/pa_unix_oss/pa_unix_oss.c	Tue Dec  2 19:57:47 2003
@@ -42,6 +42,8 @@
 
 #ifdef __linux__
 #include <linux/soundcard.h>
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h> /* JH20010905 */
 #endif
