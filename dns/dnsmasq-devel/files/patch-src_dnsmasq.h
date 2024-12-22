--- src/dnsmasq.h.orig	2024-12-20 21:57:21 UTC
+++ src/dnsmasq.h
@@ -339,7 +339,7 @@ union all_addr {
   struct datablock {
     unsigned short rrtype;
     unsigned char datalen; /* also length of SOA in negative records. */
-    char data[];
+    char data[1];
   } rrdata;
 };
 
@@ -1667,7 +1667,7 @@ typedef union {
 
 /* bpf.c or netlink.c */
 typedef union {
-	int (*af_unspec)(int family, char *addrp, char *mac, size_t maclen, void *parmv);
+	int (*af_unspec)(int family, void *addrp, char *mac, size_t maclen, void *parmv);
 	int (*af_inet)(struct in_addr local, int if_index, char *label, struct in_addr netmask, struct in_addr broadcast, void *vparam);
 	int (*af_inet6)(struct in6_addr *local, int prefix, int scope, int if_index, int flags, unsigned int preferred, unsigned int valid, void *vparam);
 	int (*af_local)(int index, unsigned int type, char *mac, size_t maclen, void *parm);
