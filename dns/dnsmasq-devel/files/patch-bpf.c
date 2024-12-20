--- src/bpf.c.orig	2024-12-19 00:36:42 UTC
+++ src/bpf.c
@@ -100,14 +100,14 @@ int arp_enumerate(void *parm, callback_t callback)
 #endif /* defined(HAVE_BSD_NETWORK) && !defined(__APPLE__) */
 
 
-int iface_enumerate(int family, void *parm, int (*callback)())
+int iface_enumerate(int family, void *parm, callback_t callback)
 {
   struct ifaddrs *head, *addrs;
   int errsave, fd = -1, ret = 0;
 
   if (family == AF_UNSPEC)
 #if defined(HAVE_BSD_NETWORK) && !defined(__APPLE__)
-    return  arp_enumerate(parm, callback.af_unspec);
+    return  arp_enumerate(parm, callback);
 #else
   return 0; /* need code for Solaris and MacOS*/
 #endif
