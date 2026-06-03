--- src/lib/kStuff/include/k/kHlpAssert.h.orig	2026-02-09 14:09:58 UTC
+++ src/lib/kStuff/include/k/kHlpAssert.h
@@ -59,6 +59,8 @@ extern "C" {
 # define kHlpAssertBreakpoint() do { __asm__ __volatile__ ("unimp 0"); } while (0) /*??*/
 #elif defined(__GNUC__) && (K_ARCH == K_ARCH_SPARC_64)
 # define kHlpAssertBreakpoint() do { __asm__ __volatile__ ("illtrap 0"); } while (0) /*??*/
+#elif defined(__GNUC__) && (K_ARCH == K_ARCH_POWERPC_32 || K_ARCH == K_ARCH_POWERPC_64)
+# define kHlpAssertBreakpoint() do { __asm__ __volatile__ ("trap"); } while (0)
 #else
 # error "Port Me"
 #endif
