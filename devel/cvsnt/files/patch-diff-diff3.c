--- diff/diff3.c.orig	2007-11-06 23:59:45.000000000 +0600
+++ diff/diff3.c	2007-11-06 23:59:05.000000000 +0600
@@ -1367,7 +1367,7 @@
   char const **ap;
   char *diffout;
   char *difffn;
-  char *encoding;
+  char *encoding = NULL;
 
   TRACE(3, "read_diff() - process arguments");
   ap = argv;
