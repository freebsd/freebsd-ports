Allow to build Rust with LLVM 16 on FreeBSD

LLVM 15 and later treat -Wimplicit-function-declaration as errors by default
when using the C99 standard or later [1].

lzma-sys from Rust tries to use gettimeofday(2) unavailable in C99 instead of
correctly detecting that FreeBSD provides clock_gettime(2).

Patch lzma-sys to indicate that it can use clock_gettime(2) on FreeBSD that is
defined in sys/time.h and available in C99.

[1] https://reviews.llvm.org/D122983

--- vendor/lzma-sys/config.h.orig	2023-09-05 17:29:57.729706000 +0000
+++ vendor/lzma-sys/config.h	2023-09-05 17:28:40.269213000 +0000
@@ -39,7 +39,7 @@
     #define MYTHREAD_POSIX 1
 #endif
 
-#if defined(__sun)
+#if defined(__sun) || defined(__FreeBSD__)
     #define HAVE_CLOCK_GETTIME 1
     #define HAVE_DECL_CLOCK_MONOTONIC 1
 #endif
