CVE-2006-3464,3465
===================================================================
--- libtiff/tif_print.c.orig	2008-08-17 13:03:49.113994690 -0400
+++ libtiff/tif_print.c	2008-08-17 13:03:52.201994368 -0400
@@ -491,7 +491,7 @@
 		} else
 			fprintf(fd, "(present)\n");
 	}
-	if (TIFFFieldSet(tif, FIELD_SUBIFD)) {
+	if (TIFFFieldSet(tif, FIELD_SUBIFD) && (td->td_subifd)) {
 		fprintf(fd, "  SubIFD Offsets:");
 		for (i = 0; i < td->td_nsubifd; i++)
 			fprintf(fd, " %5lu", (long) td->td_subifd[i]);
