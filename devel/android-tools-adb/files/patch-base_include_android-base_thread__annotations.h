--- base/include/android-base/thread_annotations.h.orig	2019-07-17 19:54:09 UTC
+++ base/include/android-base/thread_annotations.h
@@ -18,7 +18,11 @@
 
 #include <mutex>
 
+#ifdef __clang__
 #define THREAD_ANNOTATION_ATTRIBUTE__(x) __attribute__((x))
+#else
+#define THREAD_ANNOTATION_ATTRIBUTE__(x)
+#endif
 
 #define CAPABILITY(x) \
       THREAD_ANNOTATION_ATTRIBUTE__(capability(x))
