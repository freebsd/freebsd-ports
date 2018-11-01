--- src/racket/sconfig.h.orig	2018-10-30 18:06:25 UTC
+++ src/racket/sconfig.h
@@ -350,7 +350,6 @@
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "aarch64-freebsd"
 # elif defined(__powerpc__)
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-freebsd"
-#  define MZ_USE_JIT_PPC
 # else
 #  error Unported platform.
 # endif
