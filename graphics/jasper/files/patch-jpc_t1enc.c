--- src/libjasper/jpc/jpc_t1enc.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_t1enc.c	2013-04-17 22:32:23.000000000 +0200
@@ -219,7 +219,7 @@
 
 	cblk->numpasses = (cblk->numbps > 0) ? (3 * cblk->numbps - 2) : 0;
 	if (cblk->numpasses > 0) {
-		cblk->passes = jas_malloc(cblk->numpasses * sizeof(jpc_enc_pass_t));
+		cblk->passes = jas_malloc2(cblk->numpasses, sizeof(jpc_enc_pass_t));
 		assert(cblk->passes);
 	} else {
 		cblk->passes = 0;
