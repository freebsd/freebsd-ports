--- tools/vmalloc/malloc.c.orig	Thu Apr 26 20:59:21 2001
+++ tools/vmalloc/malloc.c	Thu Nov  8 17:14:01 2001
@@ -345,7 +345,9 @@
 #define malloc	______malloc
 #define realloc	______realloc
 
-#include	<malloc.h>
+#ifndef __STDC__
+#include <malloc.h>
+#endif
 
 #if _lib_mallopt
 #if __STD_C
