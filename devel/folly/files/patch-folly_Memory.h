--- folly/Memory.h.orig	2019-06-16 07:33:44 UTC
+++ folly/Memory.h
@@ -57,7 +57,8 @@ inline void deallocateBytes(void* p, size_t n) {
     (defined(__ANDROID__) && (__ANDROID_API__ > 16)) ||   \
     (defined(__APPLE__) &&                                \
      (__MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_6 ||    \
-      __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_3_0))
+      __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_3_0)) || \
+    defined(__FreeBSD__)
 
 inline void* aligned_malloc(size_t size, size_t align) {
   // use posix_memalign, but mimic the behaviour of memalign
