--- ./mgsocket.h.orig	Sat Nov  4 05:04:00 2006
+++ ./mgsocket.h	Wed Dec  6 14:02:01 2006
@@ -30,6 +30,7 @@
 #else
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <sys/un.h>
