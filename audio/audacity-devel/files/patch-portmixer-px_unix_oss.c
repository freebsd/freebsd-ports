--- lib-src/portmixer/px_unix_oss/px_unix_oss.c.orig	Tue Dec  2 20:06:55 2003
+++ lib-src/portmixer/px_unix_oss/px_unix_oss.c	Tue Dec  2 20:07:09 2003
@@ -37,6 +37,8 @@
 
 #ifdef __linux__
 #include <linux/soundcard.h>
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h> /* JH20010905 */
 #endif
