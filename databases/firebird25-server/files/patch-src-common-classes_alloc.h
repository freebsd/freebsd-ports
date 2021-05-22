--- src/common/classes/alloc.h	2021-05-19 19:28:30.698498000 -0500
+++ src/common/classes/alloc.h	2021-05-19 19:29:17.345552000 -0500
@@ -92,7 +92,7 @@
 const int MAX_TREE_DEPTH = 4;
 
 // Alignment for all memory blocks. Sizes of memory blocks in headers are measured in this units
-const size_t ALLOC_ALIGNMENT = FB_ALIGNMENT;
+#define ALLOC_ALIGNMENT 16
 
 static inline size_t MEM_ALIGN(size_t value)
 {
