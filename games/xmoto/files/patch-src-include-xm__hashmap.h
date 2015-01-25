--- src/include/xm_hashmap.h.orig	2015-01-12 23:04:54.000000000 +0100
+++ src/include/xm_hashmap.h	2015-01-12 23:07:53.000000000 +0100
@@ -13,13 +13,18 @@
 #include <hash_map>
 namespace HashNamespace=std;
 #endif
-struct hashcmp_str {
-  bool operator()(const char* s1, const char* s2) {
-    if(s1 == NULL || s2 == NULL) {
-      return false;
+
+#ifdef _LIBCPP_VERSION
+namespace __gnu_cxx {
+  template<> struct hash<std::string>
+    : public unary_function<std::string, size_t>
+  {
+    size_t operator()(const std::string& s) const
+    {
+      return hash<const char*>()(s.c_str());
     }
-    return strcmp(s1, s2) == 0;
-  }
-};
+  };
+}
+#endif // _LIBCPP_VERSION
 
 #endif
