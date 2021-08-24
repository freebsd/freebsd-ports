--- compiler-rt/lib/sanitizer_common/sanitizer_platform_interceptors.h.orig
+++ compiler-rt/lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -576,7 +576,7 @@
 #define SANITIZER_INTERCEPT_PTHREAD_ATFORK SI_NETBSD
 #define SANITIZER_INTERCEPT_GETENTROPY SI_FREEBSD
 #define SANITIZER_INTERCEPT_QSORT \
-  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS && !SI_ANDROID)
+  (SI_POSIX && !SI_IOSSIM && !SI_WATCHOS && !SI_TVOS && !SI_ANDROID && !SI_FREEBSD)
 #define SANITIZER_INTERCEPT_QSORT_R SI_GLIBC
 // sigaltstack on i386 macOS cannot be intercepted due to setjmp()
 // calling it and assuming that it does not clobber registers.
