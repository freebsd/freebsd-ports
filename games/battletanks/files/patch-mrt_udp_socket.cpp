--- mrt/udp_socket.cpp.orig	2007-09-13 12:28:11.000000000 +0700
+++ mrt/udp_socket.cpp	2008-03-27 06:19:44.000000000 +0600
@@ -7,6 +7,7 @@
 #	include <sys/socket.h>
 #	include <netinet/in.h>
 #	include <netinet/tcp.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #	include <arpa/inet.h>
 #	include <netdb.h>
