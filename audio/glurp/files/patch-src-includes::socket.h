--- src/includes.h.orig	Wed Jun  9 16:41:28 2004
+++ src/includes.h	Sat Jun  5 21:01:51 2004
@@ -11,6 +11,7 @@
 #define N_(str) str
 #endif
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
