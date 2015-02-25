--- src/stream.c.orig	2015-02-16 11:47:30.000000000 +0200
+++ src/stream.c	2015-02-16 11:48:03.000000000 +0200
@@ -19,6 +19,8 @@
 
 #include <osmocom/netif/stream.h>
 
+#include <netinet/in.h>
+
 /*
  * Client side.
  */
