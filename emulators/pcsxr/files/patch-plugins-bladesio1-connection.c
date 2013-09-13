--- plugins/bladesio1/connection.c.orig	2013-09-12 09:19:20.862489051 +0200
+++ plugins/bladesio1/connection.c	2013-09-12 09:20:25.386489200 +0200
@@ -25,6 +25,7 @@
 #if defined _WINDOWS
 #include <winsock2.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
