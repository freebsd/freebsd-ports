--- cp/g++.c.orig	Mon Nov 20 14:08:53 1995
+++ cp/g++.c	Mon Mar 20 13:29:12 2000
@@ -415,7 +415,7 @@
   programname = p;
 
   if (argc == 1)
-    fatal ("No input files specified.\n");
+    fatal ("No input files specified");
 
 #ifndef __MSDOS__
   /* We do a little magic to find out where the main gcc executable
