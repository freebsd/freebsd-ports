--- src/dns.h.orig	Fri Jul  1 14:33:35 2005
+++ src/dns.h		Sun Oct 30 09:04:28 2005
@@ -27,6 +27,9 @@
 
 #include <config.h>
 #include <arpa/inet.h>
+#if TARGET==TARGET_BSD
+#include <sys/socket.h>
+#endif
 #include <sys/socket.h>
 #include <net/if.h>
 #include <sys/types.h>
