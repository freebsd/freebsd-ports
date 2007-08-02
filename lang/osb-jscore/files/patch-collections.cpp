--- kjs/collector.cpp.orig	2007-08-02 14:42:10.000000000 +0200
+++ kjs/collector.cpp	2007-08-02 14:42:57.000000000 +0200
@@ -246,7 +246,7 @@
 
 
 // cells are 8-byte aligned 
-#define IS_POINTER_ALIGNED(p) (((int)(p) & 7) == 0)
+#define IS_POINTER_ALIGNED(p) (((intptr_t)(p) & 7) == 0)
 
 void Collector::markStackObjectsConservatively(void *start, void *end)
 {
