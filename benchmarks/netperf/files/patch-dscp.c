--- src/dscp.c.orig	2012-04-04 08:51:29.000000000 +0900
+++ src/dscp.c	2012-08-24 11:12:14.866495927 +0900
@@ -50,6 +50,7 @@
  */
 
 #if HAVE_NETINET_IN_SYSTM_H
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #if HAVE_NETINET_IP_H
