--- ../compiler-rt-11.0.0.src/lib/sanitizer_common/sanitizer_platform_interceptors.h.orig
+++ ../compiler-rt-11.0.0.src/lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -597,7 +597,7 @@
 #define SANITIZER_INTERCEPT_PTHREAD_ATFORK SI_NETBSD
 #define SANITIZER_INTERCEPT_GETENTROPY SI_FREEBSD
 #define SANITIZER_INTERCEPT_QSORT \
-  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS && !SI_ANDROID)
+  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS && !SI_ANDROID && !SI_FREEBSD)
 #define SANITIZER_INTERCEPT_QSORT_R (SI_LINUX && !SI_ANDROID)
 // sigaltstack on i386 macOS cannot be intercepted due to setjmp()
 // calling it and assuming that it does not clobber registers.
