--- ./parse.c.orig	1995-12-19 23:26:39.000000000 +0100
+++ ./parse.c	2014-03-29 18:28:41.999944284 +0100
@@ -1486,8 +1486,7 @@
        *filename;
 {
   int i;
-  char *suffix,
-       *strstr();
+  char *suffix;
   FILE *fp;
 
   strcpy (filename, &option[1]);
