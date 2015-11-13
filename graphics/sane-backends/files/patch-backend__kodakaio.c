--- backend/kodakaio.c.orig	2015-09-26 00:53:42 UTC
+++ backend/kodakaio.c
@@ -207,6 +207,10 @@ normal levels. This system is a plan rat
 #include <math.h>
 #include <poll.h>
 #include <time.h>
+#include <sys/types.h>
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
 
 #if WITH_AVAHI
 /* used for auto detecting network printers  */
