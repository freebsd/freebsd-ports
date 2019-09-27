--- src/lib/utils/tcpsocket.h.orig	2018-12-26 15:38:15 UTC
+++ src/lib/utils/tcpsocket.h
@@ -21,6 +21,7 @@
 
 #include <unistd.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/time.h>
 #include <stdint.h>
 #include <string>
