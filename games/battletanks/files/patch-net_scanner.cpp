--- net/scanner.cpp.orig	2007-12-21 19:28:34.000000000 +0600
+++ net/scanner.cpp	2008-03-27 06:20:31.000000000 +0600
@@ -13,6 +13,7 @@
 #else
 #	include <sys/socket.h>
 #	include <netinet/in.h>
+#	include <netinet/in_systm.h>
 #	include <netinet/ip.h> /* superset of previous */
 #endif
 
