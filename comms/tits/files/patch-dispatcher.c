--- dispatcher.c.orig	Tue Sep 24 13:21:42 2002
+++ dispatcher.c	Tue Sep 24 13:23:15 2002
@@ -131,7 +131,7 @@
 	struct context *ctx;
 	struct client_ctx *cc;
 	struct pollfd *pf;
-	nfds_t pfds;
+	unsigned int pfds;
 	int nfds, errcnt = 0;
 
 	while (!TAILQ_EMPTY(&contexts)) {
