Index: src/alloc.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/alloc.c,v
retrieving revision 1.106
diff -u -r1.106 alloc.c
--- src/alloc.c	2005/02/03 16:14:04	1.106
+++ src/alloc.c	2005/02/23 00:01:18
@@ -349,7 +349,7 @@
 
 #else /* ERROR_CHECK_MALLOC */
 
-#define MALLOC_BEGIN(block)
+#define MALLOC_BEGIN()
 #define FREE_OR_REALLOC_BEGIN(block)
 #define MALLOC_END()
 
