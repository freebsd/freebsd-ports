--- pbl.h.orig	2011-05-23 18:11:38.000000000 +0200
+++ pbl.h	2011-05-23 18:16:48.000000000 +0200
@@ -643,7 +643,11 @@
 /**
  * The heap.
  */
+#ifdef __cplusplus
+typedef PblList PblHeap;
+#else
 typedef struct PblList PblHeap;
+#endif
 
 /**
  * The priority queue entry struct.
@@ -663,7 +667,11 @@
 /**
  * The priority queue.
  */
+#ifdef __cplusplus
+typedef PblList PblPriorityQueue;
+#else
 typedef struct PblList PblPriorityQueue;
+#endif
 
 /*****************************************************************************/
 /* variable declarations                                                     */
