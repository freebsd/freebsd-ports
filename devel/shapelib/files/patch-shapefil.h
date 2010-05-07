--- shapefil.h.orig	2010-01-28 19:34:34.000000000 +0800
+++ shapefil.h	2010-05-01 05:04:28.000000000 +0800
@@ -126,6 +126,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef USE_DBMALLOC
 #include <dbmalloc.h>
