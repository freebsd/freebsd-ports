--- zlib/deflate.c.orig	2022-11-09 18:15:37 UTC
+++ zlib/deflate.c
@@ -58,7 +58,7 @@
  * Perforce change. Disable neon speedup (for now)
  * on Apple M1 builds.
 */
-#if ( defined( OS_DARWIN ) || defined( OS_MACOSX ) ) && defined(__aarch64__)
+#if ( defined( OS_DARWIN ) || defined( OS_MACOSX ) ) && defined(__aarch64__) || defined( OS_FREEBSD )
 #undef __ARM_NEON__
 #undef __ARM_NEON
 #endif
