--- src/pooler.c.orig	2020-05-26 09:38:55 UTC
+++ src/pooler.c
@@ -127,16 +127,16 @@ static bool add_listen(int af, const struct sockaddr *
 	 * unportable, so perhaps better to avoid it.)
 	 */
 	if (af != AF_UNIX && cf_so_reuseport) {
-#if defined(SO_REUSEPORT)
+#if defined(SO_REUSEPORT_LB)
 		int val = 1;
-		errpos = "setsockopt/SO_REUSEPORT";
-		res = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, &val, sizeof(val));
+		errpos = "setsockopt/SO_REUSEPORT_LB";
+		res = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT_LB, &val, sizeof(val));
 		if (res < 0)
 			goto failed;
-#elif defined(SO_REUSEPORT_LB)
+#elif defined(SO_REUSEPORT)
 		int val = 1;
-		errpos = "setsockopt/SO_REUSEPORT_LB";
-		res = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT_LB, &val, sizeof(val));
+		errpos = "setsockopt/SO_REUSEPORT";
+		res = setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, &val, sizeof(val));
 		if (res < 0)
 			goto failed;
 #else
