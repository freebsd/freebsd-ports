--- src/sp_identify.c.orig	Sun Dec  9 00:35:01 2001
+++ src/sp_identify.c	Sun Dec  9 00:35:22 2001
@@ -26,6 +26,8 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
+#include <sys/time.h>
+
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
