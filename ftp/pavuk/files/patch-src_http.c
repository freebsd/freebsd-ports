
$FreeBSD$

--- src/http.c.orig	Mon Jul 30 00:06:40 2001
+++ src/http.c	Fri Jul  2 18:08:05 2004
@@ -1111,8 +1111,8 @@
 	if (!loc)
 		return -1;
 
-	if (sscanf(loc, "http://%[.0-9A-Za-z_-]:%d", proxy, &port) < 1)
-		if (sscanf(loc, "%[.0-9A-Za-z_-]:%d", proxy, &port) !=2)
+	if (sscanf(loc, "http://%255[.0-9A-Za-z_-]:%d", proxy, &port) < 1)
+		if (sscanf(loc, "%255[.0-9A-Za-z_-]:%d", proxy, &port) !=2)
 			return -1;
 
 	_free(docp->http_proxy);
