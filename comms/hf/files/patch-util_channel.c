--- util/channel.c.orig	Sun Jul 30 12:11:34 2006
+++ util/channel.c	Sun Jul 30 12:12:23 2006
@@ -68,7 +68,12 @@
 #ifdef HAVE_SYS_SOUNDCARD_H
 #include <sys/soundcard.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <endian.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
 #endif
 
 #ifdef DISABLE_REALTIME
