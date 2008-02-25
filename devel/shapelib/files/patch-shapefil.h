--- shapefil.h.orig	Mon Apr  7 21:03:22 2003
+++ shapefil.h	Fri Jan 12 01:46:29 2007
@@ -115,6 +115,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef USE_DBMALLOC
 #include <dbmalloc.h>
