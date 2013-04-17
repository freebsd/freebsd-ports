--- src/libjasper/jpc/jpc_mqdec.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_mqdec.c	2013-04-17 22:32:23.000000000 +0200
@@ -118,7 +118,7 @@
 	mqdec->in = in;
 	mqdec->maxctxs = maxctxs;
 	/* Allocate memory for the per-context state information. */
-	if (!(mqdec->ctxs = jas_malloc(mqdec->maxctxs * sizeof(jpc_mqstate_t *)))) {
+	if (!(mqdec->ctxs = jas_malloc2(mqdec->maxctxs, sizeof(jpc_mqstate_t *)))) {
 		goto error;
 	}
 	/* Set the current context to the first context. */
