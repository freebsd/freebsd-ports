--- src/dscp.c.orig	2012-10-11 20:42:06 UTC
+++ src/dscp.c
@@ -54,6 +54,7 @@ const char * iptos2str(int iptos);
  */
 
 #if HAVE_NETINET_IN_SYSTM_H
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #if HAVE_NETINET_IP_H
