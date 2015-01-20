--- po6/net/ipaddr.h.orig	2015-01-05 09:06:24.000000000 +0100
+++ po6/net/ipaddr.h	2015-01-05 09:12:13.000000000 +0100
@@ -42,6 +42,10 @@
 #include <sys/socket.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#endif
+
 // STL
 #include <string>
 
