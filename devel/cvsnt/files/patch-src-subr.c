--- src/subr.c.orig	Fri Jan 23 18:54:50 2004
+++ src/subr.c	Fri Jan 23 18:55:17 2004
@@ -20,6 +20,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/socket.h>
 #include <netdb.h>
 #endif
 #include <errno.h>
