--- ./gold/gold.h	2013-08-31 12:57:14.000000000 +0100
+++ ./gold/gold.h	2013-08-31 12:59:04.000000000 +0100
@@ -65,8 +65,27 @@
 #endif
 
 // Figure out how to get a hash set and a hash map.
+#ifdef __clang__
+#if __has_include(<unordered_set>)
+#define HAVE_CXX11_UNORDERED_SET 1
+#define HAVE_TR1_UNORDERED_SET
+#define HAVE_TR1_UNORDERED_MAP
+#endif
+#endif
+#if HAVE_CXX11_UNORDERED_SET
+
+#include <unordered_set>
+#include <unordered_map>
+
+// We need a template typedef here.
+
+#define Unordered_set std::unordered_set
+#define Unordered_map std::unordered_map
+#define Unordered_multimap std::unordered_multimap
+
+#define reserve_unordered_map(map, n) ((map)->rehash(n))
 
-#if defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
+#elif defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
     && defined(HAVE_TR1_UNORDERED_MAP_REHASH)
 
 #include <tr1/unordered_set>
