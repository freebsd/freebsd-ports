--- src/main.c.orig	Sun May 12 22:59:38 2002
+++ src/main.c	Sun May 12 22:59:51 2002
@@ -62,7 +62,7 @@
 long lastpos;
 long endpos;
 long fsize;
-long val_size;
+off_t val_size;
 int no_of_reads;
 struct stat finfo;
 int is_initial_read = 0;
