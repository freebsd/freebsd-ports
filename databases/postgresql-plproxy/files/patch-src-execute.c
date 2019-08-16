HAVE_NETINET_IN_H and HAVE_SYS_SOCKET_H were removed from pg_config.h in PostgreSQL 10
HAVE_NETINET_TCP_H was removed from pg_config.h in PostgreSQL 11

--- src/execute.c.orig	2017-10-08 08:53:35 UTC
+++ src/execute.c
@@ -28,6 +28,7 @@
 #include "plproxy.h"
 
 #include <sys/time.h>
+#include <sys/types.h>
 
 #include "poll_compat.h"
 
@@ -35,15 +36,9 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #endif
-#ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
-#endif
-#ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
-#endif
-#ifdef HAVE_NETINET_TCP_H
 #include <netinet/tcp.h>
-#endif
 #ifdef HAVE_ARPA_INET_H
 #include <arpa/inet.h>
 #endif
