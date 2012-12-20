--- backend/kodakaio.c.orig	2012-08-10 09:33:29.000000000 +0900
+++ backend/kodakaio.c	2012-08-29 16:35:36.000000000 +0900
@@ -165,6 +165,10 @@
 #include <math.h>
 #include <poll.h>
 #include <time.h>
+#include <sys/types.h>
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
 
 #if HAVE_CUPS
 /* used for auto detecting network printers  */
