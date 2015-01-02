--- src/cpusupport.h.orig	2012-12-17 23:17:07 UTC
+++ src/cpusupport.h
@@ -33,7 +33,9 @@
    on a host without those instructions. Therefore we disable
    the query both if the compiler isn't supporting SSE, and on
    targets which are guaranteed to have SSE. */
-# if !defined(__SSE__) || defined(_M_X64) || defined(__amd64__)
+/* XXX  GCC on FreeBSD 9 does not have <cpuid.h>.  On i386, __SSE__ can
+   appear with -march=CPU-TYPE, so disable the SSE check completely. */
+# if !defined(__SSE__) || defined(_M_X64) || defined(__amd64__) || defined(__i386__)
 #  define query_cpu_support() 0
 # else
 
