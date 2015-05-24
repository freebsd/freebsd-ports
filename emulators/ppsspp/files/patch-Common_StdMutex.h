--- Common/StdMutex.h.orig	2015-02-26 20:05:06 UTC
+++ Common/StdMutex.h
@@ -4,12 +4,10 @@
 #define GCC_VER(x,y,z) ((x) * 10000 + (y) * 100 + (z))
 #define GCC_VERSION GCC_VER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
 
-// Note: __MAC_10_7 is defined on 10.7+.
-#if (GCC_VERSION >= GCC_VER(4,4,0) && __GXX_EXPERIMENTAL_CXX0X__ || defined(__APPLE__)) \
-/* GCC 4.4 provides <mutex>, except on these platforms: */ \
-    && !defined(ANDROID) && !defined(__SYMBIAN32__) && !defined(MACGNUSTD)
+#if __cplusplus >= 201103L
 #include <mutex>
 #else
+#warning "partial <mutex> implementation"
 
 // partial <mutex> implementation for win32/pthread
 #include <algorithm>
