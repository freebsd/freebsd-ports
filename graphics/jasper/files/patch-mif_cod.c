--- src/libjasper/mif/mif_cod.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/mif/mif_cod.c	2013-04-17 22:32:23.000000000 +0200
@@ -438,8 +438,7 @@
 	int cmptno;
 	mif_cmpt_t **newcmpts;
 	assert(maxcmpts >= hdr->numcmpts);
-	newcmpts = (!hdr->cmpts) ? jas_malloc(maxcmpts * sizeof(mif_cmpt_t *)) :
-	  jas_realloc(hdr->cmpts, maxcmpts * sizeof(mif_cmpt_t *));
+	newcmpts = jas_realloc2(hdr->cmpts, maxcmpts, sizeof(mif_cmpt_t *));
 	if (!newcmpts) {
 		return -1;
 	}
