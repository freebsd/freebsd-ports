--- server/net-utils.c.orig	2017-09-12 12:00:11 UTC
+++ server/net-utils.c
@@ -23,6 +23,9 @@
 #include <fcntl.h>
 #include <stdbool.h>
 #include <string.h>
+#include <sys/types.h>
+#include <arpa/inet.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
 #include <sys/socket.h>
@@ -31,6 +34,10 @@
 
 #include "net-utils.h"
 
+#if !defined(SOL_TCP) && defined(IPPROTO_TCP)
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 /**
  * red_socket_set_keepalive:
  * @fd: a socket file descriptor
