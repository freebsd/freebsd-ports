--- include/network.h.orig	Sat Aug 12 01:02:05 2000
+++ include/network.h	Sat Aug 12 01:02:21 2000
@@ -39,7 +39,7 @@
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-#if defined(_old_linux_) || (!defined(__linux__) && !defined(sun))
+#if defined(_old_linux_) || (!defined(__linux__) && !defined(sun) && !defined(BSD))
 #include <bstring.h>
 #endif
 
