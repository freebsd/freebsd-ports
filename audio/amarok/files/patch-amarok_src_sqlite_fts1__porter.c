--- amarok/src/sqlite/fts1_porter.c.orig        Thu Feb  1 23:14:17 2007
+++ amarok/src/sqlite/fts1_porter.c     Sat Feb  3 01:51:55 2007
@@ -26,7 +26,7 @@


 #include <assert.h>
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
