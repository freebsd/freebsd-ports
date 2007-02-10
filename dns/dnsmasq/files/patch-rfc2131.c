--- src/rfc2131.c.orig	Fri Feb  9 14:35:14 2007
+++ src/rfc2131.c	Fri Feb  9 14:35:46 2007
@@ -16,6 +16,8 @@
 #define BOOTREPLY                2
 #define DHCP_COOKIE              0x63825363
 
+#define ARPHRD_EUI64             27
+
 /* The Linux in-kernel DHCP client silently ignores any packet 
    smaller than this. Sigh...........   */
 #define MIN_PACKETSZ             300
