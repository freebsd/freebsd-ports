--- src/net/udpnetwork.cxx.orig	Sun Apr 15 13:20:04 2001
+++ src/net/udpnetwork.cxx	Sun Apr 15 13:21:01 2001
@@ -67,6 +67,16 @@
   }
 #endif
 
+#ifdef IP_PORTRANGE
+  opt = IP_PORTRANGE_HIGH;
+  if (setsockopt(fd, SOL_SOCKET, IP_PORTRANGE,
+				(SSOType)&opt, sizeof(opt)) < 0) {
+    nerror("openUDPnetwork: setsockopt IP_PORTRANGE");
+    close(fd);
+    return -1;
+  }
+#endif
+
   /* bind address */
   if (bind(fd, (const struct sockaddr*)addr, sizeof(*addr)) < 0) {
     nerror("openUDPnetwork: bind");
