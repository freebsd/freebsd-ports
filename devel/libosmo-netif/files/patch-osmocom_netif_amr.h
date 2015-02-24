--- include/osmocom/netif/amr.h.orig	2015-02-23 11:51:17 UTC
+++ include/osmocom/netif/amr.h
@@ -1,6 +1,8 @@
 #ifndef _OSMO_AMR_H_
 #define _OSMO_AMR_H_
 
+#include <endian.h>
+
 /* As defined by RFC3267: Adaptive Multi-Rate (AMR) */
 
 /*
