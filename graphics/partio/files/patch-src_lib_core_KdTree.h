--- src/lib/core/KdTree.h.orig	2013-12-28 22:59:43.000000000 +0100
+++ src/lib/core/KdTree.h	2013-12-28 22:58:47.000000000 +0100
@@ -34,7 +34,11 @@
 */
 #ifndef KdTree_h
 #define KdTree_h
+#if defined(__clang__) && defined(_LIBCPP_VERSION)
+#include <numeric>
+#elif defined(__GNUC__)
 #include <ext/numeric>
+#endif
 
 namespace Partio
 {
@@ -286,7 +290,11 @@
 
     // assign sequential ids
     _ids.resize(n);
+#if defined(__clang__) && defined(_LIBCPP_VERSION)
+    std::iota(_ids.begin(), _ids.end(), 0);
+#elif defined(__GNUC__)
     __gnu_cxx::iota(_ids.begin(), _ids.end(), 0);
+#endif
 //    _ids.reserve(n);
 //    while ((int)_ids.size() < n) _ids.push_back(_ids.size());
     _sorted = 0;

