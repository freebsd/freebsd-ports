--- hfkernel/main.c.orig	Sun Jul 30 11:51:24 2006
+++ hfkernel/main.c	Sun Jul 30 11:53:03 2006
@@ -42,13 +42,20 @@
 #include <signal.h>
 #include <syslog.h>
 #include <sys/types.h>
+#ifdef __linux__
 #include <asm/byteorder.h>
+#endif
 #include <sys/soundcard.h>
 #include <sys/socket.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
+#ifdef __linux__
 #include <endian.h>
+#endif
+#ifdef __FreeBSD__ 
+#include <sys/endian.h>
+#endif
 #include <assert.h>
 
 #ifdef DISABLE_REALTIME
