--- common/getopt.c.orig	2007-11-13 23:33:47.000000000 +0100
+++ common/getopt.c	2007-11-13 23:34:27.000000000 +0100
@@ -509,7 +509,7 @@
       const struct option *pfound = NULL;
       int exact = 0;
       int ambig = 0;
-      int indfound;
+      int indfound = 0;
       int option_index;
 
       for (nameend = nextchar; *nameend && *nameend != '='; nameend++)
