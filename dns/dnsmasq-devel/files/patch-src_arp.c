--- src/arp.c.orig	2024-12-20 21:57:21 UTC
+++ src/arp.c
@@ -35,7 +35,7 @@ static time_t last = 0;
 static struct arp_record *arps = NULL, *old = NULL, *freelist = NULL;
 static time_t last = 0;
 
-static int filter_mac(int family, char *addrp, char *mac, size_t maclen, void *parmv)
+static int filter_mac(int family, void *addrp, char *mac, size_t maclen, void *parmv)
 {
   struct arp_record *arp;
 
