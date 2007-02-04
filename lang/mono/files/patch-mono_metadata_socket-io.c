--- mono/metadata/socket-io.c.orig	Wed Nov 22 18:27:54 2006
+++ mono/metadata/socket-io.c	Wed Nov 22 18:28:11 2006
@@ -2653,7 +2653,7 @@
 	struct sockaddr_in6 saddr6;
 	struct addrinfo *info = NULL, hints;
 	gint32 family;
-	char hostname[1024] = {0};
+	char hostname[NI_MAXHOST] = {0};
 	int flags = 0;
 #else
 	struct in_addr inaddr;
