--- extern/carve/lib/triangulator.cpp.orig	2012-01-30 09:45:12.000000000 +0100
+++ extern/carve/lib/triangulator.cpp	2013-11-13 21:17:16.000000000 +0100
@@ -122,8 +122,10 @@
     std::vector<vertex_info *> queue;
 
     void checkheap() {
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
       CARVE_ASSERT(std::__is_heap(queue.begin(), queue.end(), vertex_info_ordering()));
+#elif defined(__clang__) && defined(_LIBCPP_VERSION)
+      CARVE_ASSERT(std::is_heap(queue.begin(), queue.end(), vertex_info_ordering()));
 #endif
     }
 
