--- dispatcher.c.orig	2006-03-19 11:34:47 UTC
+++ dispatcher.c
@@ -237,7 +237,7 @@ dispatcher_mainloop(void)
 	struct context *ctx;
 	struct client_ctx *cc;
 	struct pollfd *pf;
-	nfds_t pfds;
+	unsigned int pfds;
 	int nfds, errcnt = 0;
 	int timeout;
 	time_t delta = 0;
