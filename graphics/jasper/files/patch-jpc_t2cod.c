--- src/libjasper/jpc/jpc_t2cod.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_t2cod.c	2013-04-17 22:32:23.000000000 +0200
@@ -573,7 +573,7 @@
 	}
 	if (pchglist->numpchgs >= pchglist->maxpchgs) {
 		newmaxpchgs = pchglist->maxpchgs + 128;
-		if (!(newpchgs = jas_realloc(pchglist->pchgs, newmaxpchgs * sizeof(jpc_pchg_t *)))) {
+		if (!(newpchgs = jas_realloc2(pchglist->pchgs, newmaxpchgs, sizeof(jpc_pchg_t *)))) {
 			return -1;
 		}
 		pchglist->maxpchgs = newmaxpchgs;
