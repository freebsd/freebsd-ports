CVE-2006-3461
===================================================================
--- libtiff/tif_pixarlog.c.orig	2008-08-17 13:03:48.986994374 -0400
+++ libtiff/tif_pixarlog.c	2008-08-17 13:03:52.894064968 -0400
@@ -768,7 +768,19 @@
 	if (tif->tif_flags & TIFF_SWAB)
 		TIFFSwabArrayOfShort(up, nsamples);
 
-	for (i = 0; i < nsamples; i += llen, up += llen) {
+	/* 
+	 * if llen is not an exact multiple of nsamples, the decode operation
+	 * may overflow the output buffer, so truncate it enough to prevent that
+	 * but still salvage as much data as possible.
+	 * -- taviso@google.com 14th June 2006
+	 */
+	if (nsamples % llen) 
+		TIFFWarningExt(tif->tif_clientdata, module,
+				"%s: stride %lu is not a multiple of sample count, "
+				"%lu, data truncated.", tif->tif_name, llen, nsamples);
+				
+	
+	for (i = 0; i < nsamples - (nsamples % llen); i += llen, up += llen) {
 		switch (sp->user_datafmt)  {
 		case PIXARLOGDATAFMT_FLOAT:
 			horizontalAccumulateF(up, llen, sp->stride,
