--- shapefil.h.orig	2011-07-24 14:15:51.000000000 +0800
+++ shapefil.h	2011-12-24 03:00:00.000000000 +0800
@@ -138,6 +138,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef USE_DBMALLOC
 #include <dbmalloc.h>
