--- src/mydns/recursive.c.orig	Mon Apr 30 08:17:52 2007
+++ src/mydns/recursive.c	Mon Apr 30 08:22:13 2007
@@ -109,8 +109,7 @@
 #endif
 
 	/* Send to remote server */
-	if ((rv = sendto(t->recursive_fd, query, querylen, 0,
-						  (struct sockaddr *)&recursive_sa, sizeof(struct sockaddr_in))) != querylen)
+	if ((rv = send(t->recursive_fd, query, querylen, 0)) != querylen)
 	{
 		if (errno == EAGAIN)
 		{
