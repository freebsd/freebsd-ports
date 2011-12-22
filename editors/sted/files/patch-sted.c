--- sted.c.orig	2011-12-22 00:15:01.000000000 +0800
+++ sted.c	2011-12-22 00:15:09.000000000 +0800
@@ -74,7 +74,7 @@ rad *head = NULL;		/* The head pointer f
  * user. Processes the input and stores it.
  **************************************************************************/
 
-void
+int
 main (int argc, char *argv[])
 {
   int count = 0, count2 = 0, count3 = 0, c, x = 0, y = 0;
