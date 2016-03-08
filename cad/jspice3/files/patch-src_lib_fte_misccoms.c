--- src/lib/fte/misccoms.c.orig	2001-05-01 20:58:18 UTC
+++ src/lib/fte/misccoms.c
@@ -284,7 +284,7 @@ wordlist *wl;
                                 pl->pl_title,
                                 pl->pl_name);
             }
-            (void) SCEDfgets(buf,BSIZE_SP,cp_in,zz);
+            (void) SCEDfgets(buf, sizeof buf,cp_in,zz);
 
             if ((*buf == 'y') || (*buf == 'Y') || (*buf == '\n'))
                 byemesg();
