--- shapefil.h.orig	2008-11-12 22:28:15.000000000 +0800
+++ shapefil.h	2009-09-05 05:33:07.000000000 +0800
@@ -123,6 +123,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef USE_DBMALLOC
 #include <dbmalloc.h>
