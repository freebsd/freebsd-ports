--- lib/iolib.c.orig	1993-02-09 16:35:24 UTC
+++ lib/iolib.c
@@ -299,7 +299,7 @@ int length;
 }
 
 
-void fgetln(fp) /* ln is side-effected. */
+void fgetln_(fp) /* ln is side-effected. */
 FILE *fp;
 { 
     if (fp==stdin) { getln("? "); return; }
