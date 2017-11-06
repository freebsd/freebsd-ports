--- src/cl_alloc.c.orig	2017-01-20 10:40:51 UTC
+++ src/cl_alloc.c
@@ -22,7 +22,7 @@
 
 #include <stdlib.h>
 #include <assert.h>
-#include <malloc.h>
+#include <sys/types.h>
 
 static volatile int32_t cl_alloc_n = 0;
 
@@ -41,8 +41,13 @@ cl_aligned_malloc(size_t sz, size_t alig
 {
   void * p = NULL;
   atomic_inc(&cl_alloc_n);
+#ifndef __FreeBSD__
   p = memalign(align, sz);
   assert(p);
+#else
+  const int err = posix_memalign(&p,align,sz);
+  assert(err==0); 
+#endif
   return p;
 }
 
