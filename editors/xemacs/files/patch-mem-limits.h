--- src/mem-limits.h.bak	Thu Mar 18 13:08:19 2004
+++ src/mem-limits.h	Thu Mar 18 13:08:42 2004
@@ -108,7 +108,7 @@
 static POINTER data_space_start;
 
 /* Number of bytes of writable memory we can expect to be able to get */
-extern unsigned int lim_data;
+extern rlim_t lim_data;
 
 #if defined (HEAP_IN_DATA) && !defined(PDUMP)
 extern unsigned long static_heap_size;
