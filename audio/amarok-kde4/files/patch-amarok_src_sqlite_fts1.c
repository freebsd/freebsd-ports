--- amarok/src/sqlite/fts1.c.orig       Thu Feb  1 23:14:17 2007
+++ amarok/src/sqlite/fts1.c    Sat Feb  3 01:51:38 2007
@@ -19,7 +19,7 @@
 #endif

 #include <assert.h>
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
