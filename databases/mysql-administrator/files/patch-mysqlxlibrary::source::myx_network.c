--- mysqlxlibrary/source/myx_network.c.orig	Sat Feb 21 17:44:47 2004
+++ mysqlxlibrary/source/myx_network.c	Sat Feb 21 17:45:54 2004
@@ -36,6 +36,10 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
+
 #endif
 
 /*
