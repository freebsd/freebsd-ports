--- shapefil.h.orig	2011-07-24 06:15:51 UTC
+++ shapefil.h
@@ -138,6 +138,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #ifdef USE_DBMALLOC
 #include <dbmalloc.h>
