--- top.c.orig	Sat Sep 18 11:05:40 2004
+++ top.c	Sat Sep 18 11:06:55 2004
@@ -1503,7 +1503,6 @@
      char *word;
 {
   /* From readline.  */
-  extern char *filename_completion_function PARAMS ((char *, int));
   int subsequent_name;
   char **return_val;
   int return_val_used;
