--- src/lib/fte/misccoms.c.orig	Tue Feb 28 16:57:47 2006
+++ src/lib/fte/misccoms.c	Tue Feb 28 16:59:28 2006
@@ -284,7 +284,7 @@
                                 pl->pl_title,
                                 pl->pl_name);
             }
-            (void) SCEDfgets(buf,BSIZE_SP,cp_in,zz);
+            (void) SCEDfgets(buf, sizeof buf,cp_in,zz);
 
             if ((*buf == 'y') || (*buf == 'Y') || (*buf == '\n'))
                 byemesg();
