--- src/paradox.c.orig	Sun Jun  4 21:38:12 2006
+++ src/paradox.c	Sun Jun  4 21:38:31 2006
@@ -273,6 +273,7 @@
 	pxstream_t *pxs;
 	pxpindex_t *pindex;
 	int blockcount, blocknumber, numrecords;
+	TDataBlock datablockhead;
 
 	pxh = pxdoc->px_head;
 	pxs = pxdoc->px_stream;
@@ -337,7 +338,6 @@
 	if(blocknumber != 0) {
 		while(blocknumber > 0) {
 			fprintf(stderr, "next blocknumber after creating primary index: %d\n", blocknumber);
-			TDataBlock datablockhead;
 			if(get_datablock_head(pxdoc, pxs, blocknumber, &datablockhead) < 0) {
 				px_error(pxdoc, PX_RuntimeError, _("Could not get head of data block nr. %d."), blocknumber);
 				pxdoc->free(pxdoc, pindex);
