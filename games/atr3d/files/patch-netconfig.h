--- netconfig.h.orig	Wed Jun 11 11:20:08 2003
+++ netconfig.h	Wed Jun 11 11:20:31 2003
@@ -1,3 +1,5 @@
+#include <unistd.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
