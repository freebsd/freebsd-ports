--- src/bc/sconfig.h.orig	2021-07-08 17:51:36 UTC
+++ src/bc/sconfig.h
@@ -368,7 +368,6 @@
 #  define SCHEME_ARCH "aarch64"
 # elif defined(__powerpc__)
 #  define SCHEME_ARCH "ppc"
-#  define MZ_USE_JIT_PPC
 # else
 #  error Unported platform.
 # endif
