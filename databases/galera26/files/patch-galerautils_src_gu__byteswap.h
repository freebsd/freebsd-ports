--- galerautils/src/gu_byteswap.h.orig	2020-10-12 06:33:51 UTC
+++ galerautils/src/gu_byteswap.h
@@ -54,10 +54,15 @@ static GU_FORCE_INLINE uint64_t GU_ROTL64 (uint64_t x,
 #  define gu_bswap32 _OSSwapInt32
 #  define gu_bswap64 _OSSwapInt64
 #elif defined(__FreeBSD__)
-/* do not use bswapXX, because gcc44 gives old-style cast warnings */
-#  define gu_bswap16 __bswap16_var
-#  define gu_bswap32 __bswap32_var
-#  define gu_bswap64 __bswap64_var
+#  if defined(__aarch64__) || defined(__arm__)
+#    define gu_bswap16 bswap16
+#    define gu_bswap32 bswap32
+#    define gu_bswap64 bswap64
+#  else
+#    define gu_bswap16 __bswap16_var
+#    define gu_bswap32 __bswap32_var
+#    define gu_bswap64 __bswap64_var
+#  endif // __FreeBSD__
 #elif defined(__sun__)
 #  define gu_bswap16 BSWAP_16
 #  define gu_bswap32 BSWAP_32
