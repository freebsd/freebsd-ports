--- http_client.c.orig	Wed Aug  4 20:11:25 2004
+++ http_client.c	Wed Aug  4 20:12:06 2004
@@ -37,6 +37,7 @@
 # include <sys/socket.h>
 # include <sys/select.h>
 # include <netdb.h>
+# include <netinet/in.h>
 #elif defined(SYSTEM_WIN32)
 # include <winsock2.h>
 # include <ws2tcpip.h>
