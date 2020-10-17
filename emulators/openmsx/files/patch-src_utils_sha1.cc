--- src/utils/sha1.cc.orig	2020-10-16 15:25:27 UTC
+++ src/utils/sha1.cc
@@ -123,7 +123,7 @@ static inline __m128i _mm_cmple_epu8(__m128i a, __m128
 // load 64-bit (possibly unaligned) and swap bytes
 static inline uint64_t loadSwap64(const char* s)
 {
-	return Endian::bswap64(*reinterpret_cast<const uint64_t*>(s));
+	return Endian::byteswap64(*reinterpret_cast<const uint64_t*>(s));
 }
 
 #else
