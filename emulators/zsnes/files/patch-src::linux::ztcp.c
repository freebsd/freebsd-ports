--- src/linux/ztcp.c.orig	Tue May  1 21:33:14 2001
+++ src/linux/ztcp.c	Thu May  3 20:17:23 2001
@@ -92,7 +92,11 @@
 #include <netdb.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifndef __FreeBSD__
 #include <asm/ioctls.h> // for FIONREAD
+#else
+#include <sys/filio.h> // for FIONREAD
+#endif
 #else
 #include <windows.h>
 #include <winsock.h>
