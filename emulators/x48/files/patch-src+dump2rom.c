--- src/dump2rom.c.orig	Tue Sep  7 10:41:48 1999
+++ src/dump2rom.c	Sun Jun 29 10:44:05 2003
@@ -130,8 +130,7 @@
 {
   FILE *dump;
   long addr, size;
-  char ch;
-  int i, gx, error;
+  int ch, i, gx, error;
 
   if (argc < 2) {
     fprintf(stderr, "usage: %s hp48-dump-file\n", argv[0]);
