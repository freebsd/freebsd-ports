--- src/include/xm_hashmap.h.orig	2011-10-11 20:18:17 UTC
+++ src/include/xm_hashmap.h
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
