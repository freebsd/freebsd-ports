--- src/other/h2a/sort.c.orig	Sun Oct  8 13:27:07 2006
+++ src/other/h2a/sort.c	Sun Oct  8 13:27:10 2006
@@ -17,6 +17,7 @@
 static	phist	*dataBuff;
 static	phist	*dataBuff1;
 
+static BucketSort();
 
 /*
  * Sort the edge array pointed to by 'lineBuff'.  Return a pointer to a
