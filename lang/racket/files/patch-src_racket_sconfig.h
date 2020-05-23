--- src/racket/sconfig.h.orig	2020-02-07 10:30:28 UTC
+++ src/racket/sconfig.h
@@ -354,7 +354,6 @@
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "aarch64-freebsd"
 # elif defined(__powerpc__)
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-freebsd"
-#  define MZ_USE_JIT_PPC
 # else
 #  error Unported platform.
 # endif
