
$FreeBSD$

--- lib/connection.c.orig
+++ lib/connection.c
@@ -467,7 +467,8 @@
 	if (error) {
 		network_log(LOG_ERROR, s, "Unable to lookup %s:%s %s", 
 					cs->host, cs->port, gai_strerror(error));
-		freeaddrinfo(addrinfo);
+		if(addrinfo)
+			freeaddrinfo(addrinfo);
 		return FALSE;
 	}
 
