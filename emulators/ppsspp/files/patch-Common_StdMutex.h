--- Common/StdMutex.h.orig	2015-02-26 20:05:06 UTC
+++ Common/StdMutex.h
@@ -5,7 +5,8 @@
 #define GCC_VERSION GCC_VER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
 
 // Note: __MAC_10_7 is defined on 10.7+.
-#if (GCC_VERSION >= GCC_VER(4,4,0) && __GXX_EXPERIMENTAL_CXX0X__ || defined(__APPLE__)) \
+#if (__cplusplus >= 201103L || defined(__APPLE__) \
+    || (GCC_VERSION >= GCC_VER(4,4,0) && __GXX_EXPERIMENTAL_CXX0X__)) \
 /* GCC 4.4 provides <mutex>, except on these platforms: */ \
     && !defined(ANDROID) && !defined(__SYMBIAN32__) && !defined(MACGNUSTD)
 #include <mutex>
