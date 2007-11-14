--- ircd/s_zip.c.orig	2007-11-14 03:09:57.000000000 +0600
+++ ircd/s_zip.c	2007-11-14 03:10:26.000000000 +0600
@@ -116,11 +116,11 @@
 	    {
 		if (cptr->zip->in)
 			inflateEnd(cptr->zip->in);
-		MyFree((char *)cptr->zip->in);
+		MyFree(cptr->zip->in);
 		if (cptr->zip->out)
 			deflateEnd(cptr->zip->out);
-		MyFree((char *)cptr->zip->out);
-		MyFree((char *)cptr->zip);
+		MyFree(cptr->zip->out);
+		MyFree(cptr->zip);
 		cptr->zip = NULL;
 	    }
 }
