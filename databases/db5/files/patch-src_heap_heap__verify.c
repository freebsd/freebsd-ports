--- src/heap/heap_verify.c.orig	2013-09-09 15:35:08 UTC
+++ src/heap/heap_verify.c
@@ -122,7 +122,7 @@ __heap_vrfy(dbp, vdp, h, pgno, flags)
 {
 	HEAPHDR *hdr;
 	int cnt, i, j, ret;
-	db_indx_t *offsets, *offtbl, end;
+	db_indx_t *offsets = NULL, *offtbl, end;
 
 	if ((ret = __db_vrfy_datapage(dbp, vdp, h, pgno, flags)) != 0)
 		goto err;
