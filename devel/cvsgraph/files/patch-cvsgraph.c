--- cvsgraph.c.orig	Mon Feb 19 15:30:29 2001
+++ cvsgraph.c	Wed Feb 21 00:03:56 2001
@@ -1229,7 +1229,7 @@
 	}
 	else
 		fp = stdout;
-	gdImageGif(im, fp);
+	gdImagePng(im, fp);
 	if(outfile)
 		fclose(fp);
 	gdImageDestroy(im);
