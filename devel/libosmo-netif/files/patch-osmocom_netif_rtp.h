--- include/osmocom/netif/rtp.h.orig	2015-02-23 11:51:17 UTC
+++ include/osmocom/netif/rtp.h
@@ -1,6 +1,8 @@
 #ifndef _OSMO_RTP_H_
 #define _OSMO_RTP_H_
 
+#include <endian.h>
+
 /* RTP header as defined by RFC 3550 */
 struct rtp_hdr {
 #if BYTE_ORDER == LITTLE_ENDIAN
