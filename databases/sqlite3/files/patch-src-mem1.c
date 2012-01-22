--- src/mem1.c.orig	2012-01-22 16:43:59.000000000 +0400
+++ src/mem1.c	2012-01-22 16:44:42.000000000 +0400
@@ -59,7 +59,7 @@
 #define SQLITE_REALLOC(x,y) realloc((x),(y))
 
 #ifdef HAVE_MALLOC_USABLE_SIZE
-#include <malloc.h>
+#include <stdlib.h>
 #define SQLITE_MALLOCSIZE(x) malloc_usable_size(x)
 #else
 #undef SQLITE_MALLOCSIZE
