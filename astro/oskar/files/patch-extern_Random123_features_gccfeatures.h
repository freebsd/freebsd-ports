--- extern/Random123/features/gccfeatures.h.orig	2019-11-17 00:45:21 UTC
+++ extern/Random123/features/gccfeatures.h
@@ -60,7 +60,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
  Please let the authors know of any successes (or failures). */
 #endif
 
-#ifdef __powerpc__
+#if defined(__powerpc__) && !defined(__clang__)
 #include <ppu_intrinsics.h>
 #endif
 
@@ -246,6 +246,20 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY O
 #else
 #define R123_USE_MULHILO64_MULHI_INTRIN 0
 #endif
+#endif
+
+#if defined(__powerpc__) && defined(__clang__)
+#ifdef __powerpc64__
+static inline unsigned long long __mulhdu(unsigned long long a, unsigned long long b) {
+  __uint128_t c = (__uint128_t) a * (__uint128_t) b;
+  return c >> 64;
+}
+#endif
+
+static inline unsigned int __mulhwu(unsigned int a, unsigned int b) {
+  unsigned long long c = (unsigned long long) a * (unsigned long long) b;
+  return c >> 32;
+}
 #endif
 
 #ifndef R123_MULHILO64_MULHI_INTRIN
