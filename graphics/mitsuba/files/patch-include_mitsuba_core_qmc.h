--- include/mitsuba/core/qmc.h.orig	2015-07-15 10:37:38 UTC
+++ include/mitsuba/core/qmc.h
@@ -42,7 +42,7 @@ extern const int MTS_EXPORT_CORE primeTa
 /// Van der Corput radical inverse in base 2 with single precision
 inline float radicalInverse2Single(uint32_t n, uint32_t scramble = 0U) {
 	/* Efficiently reverse the bits in 'n' using binary operations */
-#if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))) || defined(__clang__)
+#if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) || defined(__clang__)
 	n = __builtin_bswap32(n);
 #else
 	n = (n << 16) | (n >> 16);
@@ -61,7 +61,7 @@ inline float radicalInverse2Single(uint3
 /// Van der Corput radical inverse in base 2 with double precision
 inline double radicalInverse2Double(uint64_t n, uint64_t scramble = 0ULL) {
 	/* Efficiently reverse the bits in 'n' using binary operations */
-#if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))) || defined(__clang__)
+#if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) || defined(__clang__)
 	n = __builtin_bswap64(n);
 #else
 	n = (n << 32) | (n >> 32);
