--- mdnsd.c.orig	2017-11-22 13:47:51 UTC
+++ mdnsd.c
@@ -13,6 +13,7 @@
 #endif
 
 #include <sys/types.h>
+#include <sys/socket.h>
 
 #ifdef _WIN32
 
@@ -139,7 +140,7 @@ int msock(void)
 	int s, flag = 1, ittl = 255;
 	struct sockaddr_in in;
 	struct ip_mreq mc;
-	char ttl = 255; // send to any reachable net, not only the subnet
+	u_char ttl = 255; // send to any reachable net, not only the subnet
 
 	memset(&in, 0, sizeof(in));
 	in.sin_family = AF_INET;
