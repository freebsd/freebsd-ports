--- src/libjasper/jpc/jpc_mqenc.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_mqenc.c	2013-04-17 22:32:23.000000000 +0200
@@ -197,7 +197,7 @@
 	mqenc->maxctxs = maxctxs;
 
 	/* Allocate memory for the per-context state information. */
-	if (!(mqenc->ctxs = jas_malloc(mqenc->maxctxs * sizeof(jpc_mqstate_t *)))) {
+	if (!(mqenc->ctxs = jas_malloc2(mqenc->maxctxs, sizeof(jpc_mqstate_t *)))) {
 		goto error;
 	}
 
