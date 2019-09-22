--- qjs.c.orig	2019-09-18 18:34:20 UTC
+++ qjs.c
@@ -130,7 +130,7 @@ static inline size_t js_trace_malloc_usable_size(void 
     return malloc_usable_size(ptr);
 #else
     /* change this to `return 0;` if compilation fails */
-    return malloc_usable_size(ptr);
+    return 0; //return malloc_usable_size(ptr);
 #endif
 }
 
@@ -246,7 +246,7 @@ static const JSMallocFunctions trace_mf = {
     (size_t (*)(const void *))malloc_usable_size,
 #else
     /* change this to `NULL,` if compilation fails */
-    malloc_usable_size,
+    NULL, //malloc_usable_size,
 #endif
 };
 
