--- lib/iolib.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ lib/iolib.c	2008-03-23 15:39:56.000000000 +0000
@@ -299,7 +299,7 @@
 }
 
 
-void fgetln(fp) /* ln is side-effected. */
+void fgetln_(fp) /* ln is side-effected. */
 FILE *fp;
 { 
     if (fp==stdin) { getln("? "); return; }
