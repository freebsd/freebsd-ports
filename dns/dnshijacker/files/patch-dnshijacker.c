--- dnshijacker.c.orig	Thu Apr 21 00:40:59 2005
+++ dnshijacker.c	Thu Apr 21 00:41:29 2005
@@ -733,7 +733,7 @@
      *  source and destination are swapped here because we are spoofing a reply
      */
 
-    libnet_build_ip(LIBNET_UDP_H + LIBNET_DNS_H,
+    libnet_build_ip(packet_size - LIBNET_IP_H,
             0,                                   /* ip tos              */
             0,                                   /* ip id               */
             0,                                   /* fragmentation bits  */
