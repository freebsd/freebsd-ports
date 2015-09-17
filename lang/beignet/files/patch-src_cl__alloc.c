--- src/cl_alloc.c.orig	2015-01-16 11:24:13.000000000 +0100
+++ src/cl_alloc.c	2015-02-03 15:31:13.983452000 +0100
@@ -22,7 +22,7 @@
 
 #include <stdlib.h>
 #include <assert.h>
-#include <malloc.h>
+#include <sys/types.h>
 
 static volatile int32_t cl_alloc_n = 0;
 
@@ -41,8 +41,13 @@
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
 
