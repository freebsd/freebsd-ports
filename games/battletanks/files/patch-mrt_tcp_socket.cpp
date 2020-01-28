--- mrt/tcp_socket.cpp.orig	2007-09-12 15:46:52.000000000 +0700
+++ mrt/tcp_socket.cpp	2008-03-27 06:19:19.000000000 +0600
@@ -26,6 +26,7 @@
 #	include <sys/socket.h>
 #	include <netinet/in.h>
 #	include <netinet/tcp.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #	include <arpa/inet.h>
 #	include <netdb.h>
