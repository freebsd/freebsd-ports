--- gold/system.h.orig	2013-11-04 16:33:39.000000000 +0100
+++ gold/system.h	2013-12-14 12:51:17.000000000 +0100
@@ -57,7 +57,20 @@
 
 // Figure out how to get a hash set and a hash map.
 
-#if defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
+#if defined(HAVE_UNORDERED_SET) && defined(HAVE_UNORDERED_MAP)
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
+
+#elif defined(HAVE_TR1_UNORDERED_SET) && defined(HAVE_TR1_UNORDERED_MAP) \
     && defined(HAVE_TR1_UNORDERED_MAP_REHASH)
 
 #include <tr1/unordered_set>
