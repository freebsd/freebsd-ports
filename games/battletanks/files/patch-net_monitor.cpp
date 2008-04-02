--- net/monitor.cpp.orig	2007-12-21 16:55:30.000000000 +0600
+++ net/monitor.cpp	2008-03-27 06:20:09.000000000 +0600
@@ -33,6 +33,7 @@
 #else
 #	include <sys/socket.h>
 #	include <netinet/in.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #	include <arpa/inet.h>
 #	include <netdb.h>
