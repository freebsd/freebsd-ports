--- zlib/deflate.c.orig	2023-04-08 02:21:18 UTC
+++ zlib/deflate.c
@@ -56,7 +56,7 @@
  * Perforce change. Disable neon speedup (for now)
  * on Apple M1 builds.
 */
-#if ( defined( OS_DARWIN ) || defined( OS_MACOSX ) ) && defined(__aarch64__)
+#if ( defined( OS_DARWIN ) || defined( OS_MACOSX ) || defined( OS_FREEBSD ) ) && defined(__aarch64__)
 #undef __ARM_NEON__
 #undef __ARM_NEON
 #endif
