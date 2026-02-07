--- kccommon.h.orig	2012-05-24 16:27:59 UTC
+++ kccommon.h
@@ -82,7 +82,7 @@
 using ::snprintf;
 }
 
-#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER)
+#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER) || defined(_LIBCPP_VERSION)
 
 #include <unordered_map>
 #include <unordered_set>
