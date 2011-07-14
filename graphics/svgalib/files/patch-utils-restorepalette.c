--- utils/restorepalette.c.orig	2011-07-01 01:41:50.000000000 +0200
+++ utils/restorepalette.c	2011-07-01 01:42:17.000000000 +0200
@@ -105,7 +105,7 @@
     }
 }
 
-void
+int
 main (int argc, char *argv[])
 {
   int i;
