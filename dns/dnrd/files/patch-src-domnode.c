--- src/domnode.c.orig	Mon Jul 19 13:17:21 2004
+++ src/domnode.c	Wed Jul 28 22:28:52 2004
@@ -26,6 +26,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
