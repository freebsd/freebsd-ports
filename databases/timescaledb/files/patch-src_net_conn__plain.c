--- src/net/conn_plain.c.orig	2018-09-12 05:10:16 UTC
+++ src/net/conn_plain.c
@@ -2,6 +2,10 @@
 #include <postgres.h>
 #include <pg_config.h>
 
+#ifndef WIN32
+#include <sys/socket.h>
+#endif
+
 #include "conn_internal.h"
 #include "conn_plain.h"
 
@@ -25,7 +29,7 @@ plain_connect(Connection *conn, const char *host, cons
 	char		strport[6];
 	struct addrinfo *ainfo,
 				hints = {
-		.ai_family = PF_UNSPEC,
+		.ai_family = AF_UNSPEC,
 		.ai_socktype = SOCK_STREAM,
 	};
 	int			ret;
