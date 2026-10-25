--- src/common/network.c.orig	2026-09-15 19:04:10 UTC
+++ src/common/network.c
@@ -166,7 +166,7 @@
 	sprintf (portstring, "%d", port);
 
 	memset (&hints, 0, sizeof (struct addrinfo));
-	hints.ai_family = PF_UNSPEC; /* support ipv6 and ipv4 */
+	hints.ai_family = AF_UNSPEC; /* support ipv6 and ipv4 */
 	hints.ai_flags = AI_CANONNAME | AI_ADDRCONFIG;
 	hints.ai_socktype = SOCK_STREAM;
 
