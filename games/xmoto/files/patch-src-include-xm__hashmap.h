--- src/include/xm_hashmap.h.orig	2019-10-23 11:51:33 UTC
+++ src/include/xm_hashmap.h
@@ -1,25 +1,11 @@
 #ifndef __XMHASHMAP_H__
 #define __XMHASHMAP_H__
 
-#ifdef __GNUC__
-#if (__GNUC__ >= 3)
-#include <ext/hash_map>
-  namespace HashNamespace=__gnu_cxx;
-#else
-#include <hash_map>
-#define HashNamespace std
-#endif
-#else // #ifdef __GNUC__
-#include <hash_map>
-namespace HashNamespace=std;
-#endif
-struct hashcmp_str {
-  bool operator()(const char* s1, const char* s2) {
-    if(s1 == NULL || s2 == NULL) {
-      return false;
-    }
-    return strcmp(s1, s2) == 0;
-  }
+#include <unordered_map>
+
+namespace HashNamespace {
+	template <class Key, class T, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator< std::pair<const Key, T> >>
+	using hash_map = std::unordered_map<Key, T, Hash, Pred, Allocator>;
 };
 
 #endif
