--- mdmdetect.c.orig	Sun Feb 11 01:02:58 2001
+++ mdmdetect.c	Tue Jul 24 00:10:05 2001
@@ -37,7 +37,16 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#ifdef NO_TERMIO
+#include <sgtty.h>
+#else
+#ifdef USE_TERMIOS
+#include <sys/ioctl.h>
+#include <termios.h>
+#else
 #include <termio.h>
+#endif /* USE_TERMIOS */
+#endif
 #ifdef SVR4
 #include <sys/mkdev.h>
 #endif /* SVR4 */
