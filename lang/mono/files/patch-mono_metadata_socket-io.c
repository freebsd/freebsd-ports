--- mono/metadata/socket-io.c.orig	Thu Jun 16 21:01:26 2005
+++ mono/metadata/socket-io.c	Thu Jun 16 21:04:19 2005
@@ -2496,7 +2496,7 @@
 	struct sockaddr_in6 saddr6;
 	struct addrinfo *info = NULL, hints;
 	gint32 family;
-	char hostname[1024] = {0};
+	char hostname[NI_MAXHOST];
 #else
 	struct in_addr inaddr;
 	struct hostent *he;
