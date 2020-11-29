--- src/bc/sconfig.h.orig	2020-10-13 22:27:26 UTC
+++ src/bc/sconfig.h
@@ -357,7 +357,6 @@
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "aarch64-freebsd"
 # elif defined(__powerpc__)
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-freebsd"
-#  define MZ_USE_JIT_PPC
 # else
 #  error Unported platform.
 # endif
