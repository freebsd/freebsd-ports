--- cvsunix/lib/regex.c.orig	2007-11-22 20:19:42.000000000 +0100
+++ cvsunix/lib/regex.c	2007-11-22 20:32:54.000000000 +0100
@@ -4909,7 +4909,7 @@
 		/* Compare that many; failure if mismatch, else move
 		   past them.  */
 		if (RE_TRANSLATE_P (translate)
-		    ? bcmp_translate (d, d2, mcnt, translate)
+		    ? bcmp_translate ((unsigned char *)d, (unsigned char *)d2, mcnt, translate)
 		    : bcmp (d, d2, mcnt))
 		  goto fail;
 		d += mcnt, d2 += mcnt;
