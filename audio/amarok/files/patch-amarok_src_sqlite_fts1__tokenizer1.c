--- amarok/src/sqlite/fts1_tokenizer1.c.orig    Thu Feb  1 23:14:17 2007
+++ amarok/src/sqlite/fts1_tokenizer1.c Sat Feb  3 01:52:07 2007
@@ -18,7 +18,7 @@


 #include <assert.h>
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
