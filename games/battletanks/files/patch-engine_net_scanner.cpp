--- ./engine/net/scanner.cpp.orig	2009-12-25 16:40:23.000000000 +0300
+++ ./engine/net/scanner.cpp	2010-04-25 13:10:51.760938402 +0400
@@ -15,6 +15,7 @@
 #else
 #	include <sys/socket.h>
 #	include <netinet/in.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #	include <arpa/inet.h>
 #endif
