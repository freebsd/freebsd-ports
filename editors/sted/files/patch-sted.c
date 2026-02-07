--- sted.c.orig	1998-05-17 13:15:08 UTC
+++ sted.c
@@ -74,7 +74,7 @@ rad *head = NULL;		/* The head pointer f
  * user. Processes the input and stores it.
  **************************************************************************/
 
-void
+int
 main (int argc, char *argv[])
 {
   int count = 0, count2 = 0, count3 = 0, c, x = 0, y = 0;
