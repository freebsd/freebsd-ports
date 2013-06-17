--- cpp.orig/include/IceUtil/Config.h	2013-03-11 15:19:46.000000000 +0000
+++ cpp/include/IceUtil/Config.h	2013-05-20 02:09:58.239194578 +0000
@@ -51,7 +51,7 @@
 // Check for C++ 11 support
 //
 #if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || \
-    (defined(__clang__) && (__clang_major__ >= 4) && __cplusplus >= 201103) || \
+    (defined(__clang__) && ((defined(__APPLE__) && __clang_major__ >= 4) || (!defined(__APPLE__) && __clang_major__ >= 3)) && __cplusplus >= 201103) || \
     (defined(_MSC_VER) && (_MSC_VER >= 1600))
 #   define ICE_CPP11
 #endif
