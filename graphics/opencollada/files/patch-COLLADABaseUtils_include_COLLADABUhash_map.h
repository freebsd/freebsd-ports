--- COLLADABaseUtils/include/COLLADABUhash_map.h.orig	2013-11-16 18:46:18.000000000 +0100
+++ COLLADABaseUtils/include/COLLADABUhash_map.h	2013-11-16 18:57:20.000000000 +0100
@@ -60,6 +60,15 @@
         #define COLLADABU_HASH_NAMESPACE_CLOSE }
         #define COLLADABU_HASH_FUN hash
     #endif
+#elif defined(__FreeBSD__) && defined(_LIBCPP_VERSION)
+    #include <unordered_map>
+    #include <unordered_set>
+    #define COLLADABU_HASH_MAP std::unordered_map
+    #define COLLADABU_HASH_MULTIMAP std::unordered_multimap
+    #define COLLADABU_HASH_SET std::unordered_set
+    #define COLLADABU_HASH_NAMESPACE_OPEN std
+    #define COLLADABU_HASH_NAMESPACE_CLOSE
+    #define COLLADABU_HASH_FUN hash
 #else   // Linux or Mac
     #if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3)
         #include <ext/hash_map>
