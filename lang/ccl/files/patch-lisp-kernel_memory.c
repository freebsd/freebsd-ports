--- lisp-kernel/memory.c.orig	2015-11-06 20:10:03 UTC
+++ lisp-kernel/memory.c
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
@@ -907,7 +907,7 @@ ReserveMemory(natural size)
                    PAGE_NOACCESS);
   return p;
 #else
-  p = mmap(NULL,size,PROT_NONE,MAP_PRIVATE|MAP_ANON|MAP_NORESERVE,-1,0);
+  p = mmap(NULL,size,PROT_NONE,MAP_PRIVATE|MAP_ANON,-1,0);
   if (p == MAP_FAILED) {
     return NULL;
   }
