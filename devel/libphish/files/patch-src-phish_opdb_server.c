--- src/phish_opdb_server.c.orig	Sun Mar 19 11:40:55 2006
+++ src/phish_opdb_server.c	Mon Jun  5 13:33:51 2006
@@ -21,6 +21,7 @@
 #define close closesocket
 #include <winsock2.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #endif
