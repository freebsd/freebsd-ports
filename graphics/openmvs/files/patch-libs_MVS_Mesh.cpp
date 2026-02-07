--- libs/MVS/Mesh.cpp.orig	2024-05-27 00:00:00 UTC
+++ libs/MVS/Mesh.cpp
@@ -35,6 +35,22 @@
 #include <boost/graph/adjacency_list.hpp>
 #include <boost/graph/filtered_graph.hpp>
 #include <boost/graph/connected_components.hpp>
+// Fix for vcglib compatibility with modern C++ standard library
+#include <algorithm>
+#include <random>
+namespace std {
+// Provide random_shuffle for C++14/17 when it's been removed
+template<class RandomIt, class RandomFunc>
+void random_shuffle(RandomIt first, RandomIt last, RandomFunc& r) {
+    std::shuffle(first, last, std::default_random_engine());
+}
+// Provide unary_function for vcglib
+template <typename ArgumentType, typename ResultType>
+struct unary_function {
+    typedef ArgumentType argument_type;
+    typedef ResultType result_type;
+};
+}
 #ifdef _MSC_VER
 #pragma warning(push)
 #pragma warning(disable: 4244 4267 4305)
