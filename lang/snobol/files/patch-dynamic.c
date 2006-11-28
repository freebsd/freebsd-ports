--- lib/generic/dynamic.c.orig	Tue Nov 28 00:09:54 2006
+++ lib/generic/dynamic.c	Tue Nov 28 00:10:30 2006
@@ -2,13 +2,13 @@
 
 /* allocate dynamic region */
 
-char *malloc();
+#include <stdlib.h>
 
 char *
 dynamic( size )
     int size;
 {
-    return malloc(size);
+    return (char *) malloc(size);
 }
 
 void
