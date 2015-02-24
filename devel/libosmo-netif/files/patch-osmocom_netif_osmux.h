--- include/osmocom/netif/osmux.h.orig	2015-02-23 11:51:17 UTC
+++ include/osmocom/netif/osmux.h
@@ -1,6 +1,8 @@
 #ifndef _OSMUX_H_
 #define _OSMUX_H_
 
+#include <endian.h>
+
 /* OSmux header:
  *
  *	ft (3 bits):		0=signalling, 1=voice
