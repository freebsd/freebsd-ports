--- ./NQ/net_dgrm.c.orig	Sat Aug 18 06:07:24 2007
+++ ./NQ/net_dgrm.c	Wed Aug 29 00:03:31 2007
@@ -22,6 +22,7 @@
 #include <windows.h>
 #include <winsock.h>
 #else
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
