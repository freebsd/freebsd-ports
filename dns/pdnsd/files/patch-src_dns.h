--- src/dns.h.orig	Fri Oct 29 01:03:35 2004
+++ src/dns.h	Fri Oct 29 01:04:55 2004
@@ -27,6 +27,9 @@
 
 #include <config.h>
 #include <arpa/inet.h>
+#if TARGET==TARGET_BSD
+#include <sys/socket.h>
+#endif
 #include <net/if.h>
 #include <sys/types.h>
 #include <inttypes.h>
