--- ../compiler-rt-10.0.0.src/lib/sanitizer_common/sanitizer_platform_interceptors.h.orig
+++ ../compiler-rt-10.0.0.src/lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -594,7 +594,7 @@
 #define SANITIZER_INTERCEPT_PTHREAD_ATFORK SI_NETBSD
 #define SANITIZER_INTERCEPT_GETENTROPY SI_FREEBSD
 #define SANITIZER_INTERCEPT_QSORT \
-  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS)
+  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS && !SI_FREEBSD)
 #define SANITIZER_INTERCEPT_QSORT_R (SI_LINUX && !SI_ANDROID)
 
 #endif  // #ifndef SANITIZER_PLATFORM_INTERCEPTORS_H
