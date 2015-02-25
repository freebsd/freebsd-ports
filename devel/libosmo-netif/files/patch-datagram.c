--- src/datagram.c.orig	2015-02-16 11:44:42.000000000 +0200
+++ src/datagram.c	2015-02-16 11:44:12.000000000 +0200
@@ -19,6 +19,8 @@
 
 #include <osmocom/netif/datagram.h>
 
+#include <netinet/in.h>
+
 /*
  * Client side.
  */
