CVE-2006-3464,3465
===================================================================
--- libtiff/tif_dirinfo.c.orig	2008-08-17 13:03:48.958994316 -0400
+++ libtiff/tif_dirinfo.c	2008-08-17 13:03:52.890034927 -0400
@@ -775,7 +775,8 @@
 		TIFFErrorExt(tif->tif_clientdata, "TIFFFieldWithTag",
 			  "Internal error, unknown tag 0x%x",
                           (unsigned int) tag);
-		assert(fip != NULL);
+		/* assert(fip != NULL); */
+
 		/*NOTREACHED*/
 	}
 	return (fip);
@@ -789,7 +790,8 @@
 	if (!fip) {
 		TIFFErrorExt(tif->tif_clientdata, "TIFFFieldWithName",
 			  "Internal error, unknown tag %s", field_name);
-		assert(fip != NULL);
+		/* assert(fip != NULL); */
+		
 		/*NOTREACHED*/
 	}
 	return (fip);
