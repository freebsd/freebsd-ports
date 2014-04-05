--- extern/carve/include/carve/mesh_ops.hpp.orig	2014-03-22 13:19:46.000000000 +0100
+++ extern/carve/include/carve/mesh_ops.hpp	2014-03-22 13:20:36.000000000 +0100
@@ -580,8 +580,10 @@
           std::vector<VertexInfo *> queue;
 
           void checkheap() {
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
             CARVE_ASSERT(std::__is_heap(queue.begin(), queue.end(), order_by_score()));
+#elif defined(__clang__) && defined(_LIBCPP_VERSION)
+            CARVE_ASSERT(std::is_heap(queue.begin(), queue.end(), order_by_score()));
 #endif
           }
 
