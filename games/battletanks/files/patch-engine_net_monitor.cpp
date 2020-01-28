--- ./engine/net/monitor.cpp.orig	2009-10-12 12:34:31.000000000 +0400
+++ ./engine/net/monitor.cpp	2010-04-25 13:10:45.059278180 +0400
@@ -47,6 +47,7 @@
 #else
 #	include <sys/socket.h>
 #	include <netinet/in.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #	include <arpa/inet.h>
 #	include <netdb.h>
