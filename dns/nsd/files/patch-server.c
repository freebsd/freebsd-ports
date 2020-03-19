--- server.c.orig	2020-03-17 10:00:17 UTC
+++ server.c
@@ -1104,7 +1104,7 @@ set_setfib(struct nsd_socket *sock)
 {
 #if defined(SO_SETFIB)
 	if(setsockopt(sock->s, SOL_SOCKET, SO_SETFIB,
-	              (const void *)(uintptr_t)sock->fib, sizeof(sock->fib)) == -1)
+	              (const void *)(uintptr_t)&sock->fib, sizeof(sock->fib)) == -1)
 	{
 		log_msg(LOG_ERR, "setsockopt(..., %s, %d, ...) failed: %s",
 		                 "SO_SETFIB", sock->fib, strerror(errno));
