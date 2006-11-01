--- audio.c.orig	Mon May  5 03:07:05 1997
+++ audio.c	Wed Oct 25 19:33:27 2006
@@ -36,7 +36,7 @@
 #include <linux/unistd.h>
 #endif
 #else /* FreeBSD? */
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #include <unistd.h>
 #define LINUX_DEFAULT_FREQ (22050)
