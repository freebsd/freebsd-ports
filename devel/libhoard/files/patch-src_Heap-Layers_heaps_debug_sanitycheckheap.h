--- Heap-Layers/heaps/debug/sanitycheckheap.h.orig	2013-10-21 01:01:57.000000000 +0200
+++ Heap-Layers/heaps/debug/sanitycheckheap.h	2016-04-07 23:39:09.104819000 +0200
@@ -27,7 +27,7 @@ namespace HL {
     /// This approach lets us use SanityCheckHeaps when we're replacing malloc.
 
     // The objects are pairs, mapping void * pointers to sizes.
-    typedef std::pair<const void *, size_t> objType;
+    typedef std::pair<void * const, size_t> objType;
 
     // The heap is a simple freelist heap.
     typedef HL::FreelistHeap<HL::ZoneHeap<HL::MmapHeap, 16384> > heapType;
