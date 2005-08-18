--- lib/dns/resolver.c.orig	Tue Feb  8 15:59:44 2005
+++ lib/dns/resolver.c	Wed Aug 17 02:42:48 2005
@@ -2665,7 +2665,7 @@
 	    unsigned int options, unsigned int bucketnum, fetchctx_t **fctxp)
 {
 	fetchctx_t *fctx;
-	isc_result_t result = ISC_R_SUCCESS;
+	isc_result_t result;
 	isc_result_t iresult;
 	isc_interval_t interval;
 	dns_fixedname_t qdomain;
@@ -2687,8 +2687,10 @@
 	strcat(buf, "/");	/* checked */
 	strcat(buf, typebuf);	/* checked */
 	fctx->info = isc_mem_strdup(res->mctx, buf);
-	if (fctx->info == NULL)
+	if (fctx->info == NULL) {
+		result = ISC_R_NOMEMORY;
 		goto cleanup_fetch;
+	}
 	FCTXTRACE("create");
 	dns_name_init(&fctx->name, NULL);
 	result = dns_name_dup(name, res->mctx, &fctx->name);
