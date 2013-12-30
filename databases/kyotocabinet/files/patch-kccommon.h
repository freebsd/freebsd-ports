--- kccommon.h.orig	2012-05-25 00:27:59.000000000 +0800
+++ kccommon.h	2013-12-28 01:25:49.838357594 +0800
@@ -82,7 +82,7 @@
 using ::snprintf;
 }
 
-#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER)
+#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER) || defined(_LIBCPP_VERSION)
 
 #include <unordered_map>
 #include <unordered_set>
