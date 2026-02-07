--- src/client.c.orig	2020-08-29 13:39:41 UTC
+++ src/client.c
@@ -213,17 +213,17 @@ static void* client_connect_async(connection *c) {
 #if defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTVL) && defined(TCP_KEEPCNT)
 	/* 10s idle before keepalive probe */
 	opt = 10;
-	if (setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, (char*)&opt, sizeof(opt)))  {
+	if (setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, (char*)&opt, sizeof(opt)))  {
 		fprintf(stderr, "setsockopt() TCP_KEEPIDLE failed on socket %d: %s\n", sock, strerror(errno));
 	}
 	/* 10s probe interval */
 	opt = 10;
-	if (setsockopt(sock, SOL_TCP, TCP_KEEPINTVL, (char*)&opt, sizeof(opt)))  {
+	if (setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, (char*)&opt, sizeof(opt)))  {
 		fprintf(stderr, "setsockopt() TCP_KEEPINTVL failed on socket %d: %s\n", sock, strerror(errno));
 	}
 	/* consider session down after 10 missed probes */
 	opt = 10;
-	if (setsockopt(sock, SOL_TCP, TCP_KEEPCNT, (char*)&opt, sizeof(opt)))  {
+	if (setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, (char*)&opt, sizeof(opt)))  {
 		fprintf(stderr, "setsockopt() TCP_KEEPCNT failed on socket %d: %s\n", sock, strerror(errno));
 	}
 #endif /* TCP_KEEPIDLE && TCP_KEEPINTVL && TCP_KEEPCNT */
