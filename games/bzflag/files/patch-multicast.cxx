--- src/net/multicast.cxx.orig	Mon Mar 26 07:21:54 2001
+++ src/net/multicast.cxx	Mon Mar 26 07:24:31 2001
@@ -174,6 +174,7 @@
   struct ip_mreq mreq;
   struct in_addr ifaddr;
   int fd;
+  unsigned int opt;
 
   /* check parameters */
   if (!addr) {
@@ -322,7 +323,7 @@
   else {
 #if defined(SO_REUSEPORT)
     /* set reuse port */
-    int opt = 1;
+    opt = 1;
     if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT,
 				(SSOType)&opt, sizeof(opt)) < 0) {
       nerror("WARNING: openMulticast: setsockopt SO_REUSEPORT");
@@ -335,7 +336,7 @@
 #if defined(_WIN32)
     BOOL opt = TRUE;
 #else
-    int opt = 1;
+    opt = 1;
 #endif
     if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
 				(SSOType)&opt, sizeof(opt)) < 0) {
@@ -384,12 +385,12 @@
 int			setMulticastTTL(int fd, int ttl)
 {
 #if defined(_WIN32)
-  unsigned int opt = (unsigned int)ttl;
+  opt = (unsigned int)ttl;
 #else /* defined(_WIN32) */
-  unsigned char opt = (unsigned char)ttl;
+  unsigned char Copt = (unsigned char)ttl;
 #endif /* defined(_WIN32) */
   return setsockopt(fd, IPPROTO_IP, IP_MULTICAST_TTL,
-				(SSOType)&opt, sizeof(opt));
+				(SSOType)&Copt, sizeof(Copt));
 }
 
 int			sendMulticast(int fd, const void* buffer,
