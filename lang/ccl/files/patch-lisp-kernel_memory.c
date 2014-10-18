--- lisp-kernel/memory.c.orig	2014-10-08 10:40:13.000000000 -0400
+++ lisp-kernel/memory.c	2014-10-08 10:41:19.000000000 -0400
@@ -89,7 +89,7 @@ ReserveMemoryForHeap(LogicalAddress want
   start = mmap((void *)want,
 	       totalsize + heap_segment_size,
 	       PROT_NONE,
-	       MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+	       MAP_PRIVATE | MAP_ANON,
 	       -1,
 	       0);
   if (start == MAP_FAILED) {
@@ -99,7 +99,7 @@ ReserveMemoryForHeap(LogicalAddress want
   if (start != want) {
     munmap(start, totalsize+heap_segment_size);
     start = (void *)((((natural)start)+heap_segment_size-1) & ~(heap_segment_size-1));
-    if(mmap(start, totalsize, PROT_NONE, MAP_PRIVATE | MAP_ANON | MAP_FIXED | MAP_NORESERVE, -1, 0) != start) {
+    if(mmap(start, totalsize, PROT_NONE, MAP_PRIVATE | MAP_ANON | MAP_FIXED, -1, 0) != start) {
       return NULL;
     }
   }
@@ -877,7 +877,7 @@ ReserveMemory(natural size)
                    PAGE_NOACCESS);
   return p;
 #else
-  p = mmap(NULL,size,PROT_NONE,MAP_PRIVATE|MAP_ANON|MAP_NORESERVE,-1,0);
+  p = mmap(NULL,size,PROT_NONE,MAP_PRIVATE|MAP_ANON,-1,0);
   if (p == MAP_FAILED) {
     return NULL;
   }
