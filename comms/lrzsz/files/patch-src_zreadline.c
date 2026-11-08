--- src/zreadline.c.orig	2026-09-24 18:08:25 UTC
+++ src/zreadline.c
@@ -53,7 +53,7 @@ readline_internal(unsigned int timeout)
 	struct timeval *tvp;
 	int rc;
 
-	DPRINTF(DEBUG_READLINE, "Calling read: timeout=%u/10s  readnum=%lu ",
+	DPRINTF(DEBUG_READLINE, "Calling read: timeout=%u/10s  readnum=%zu ",
 	  timeout, readline_readnum);
 
 	if (no_timeout) {
