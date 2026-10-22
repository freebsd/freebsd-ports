--- Zend/zend_types.h.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_types.h
@@ -439,17 +439,21 @@ struct _zend_array {
 # define HT_HASH_RESET(ht) do { \
 		char *p = (char*)&HT_HASH(ht, (ht)->nTableMask); \
 		size_t size = HT_HASH_SIZE((ht)->nTableMask); \
-		__m128i xmm0 = _mm_setzero_si128(); \
-		xmm0 = _mm_cmpeq_epi8(xmm0, xmm0); \
-		ZEND_ASSERT(size >= 64 && ((size & 0x3f) == 0)); \
-		do { \
-			_mm_storeu_si128((__m128i*)p, xmm0); \
-			_mm_storeu_si128((__m128i*)(p+16), xmm0); \
-			_mm_storeu_si128((__m128i*)(p+32), xmm0); \
-			_mm_storeu_si128((__m128i*)(p+48), xmm0); \
-			p += 64; \
-			size -= 64; \
-		} while (size != 0); \
+		if (UNEXPECTED(size < 64)) { \
+			memset(p, HT_INVALID_IDX, size); \
+		} else { \
+			__m128i xmm0 = _mm_setzero_si128(); \
+			xmm0 = _mm_cmpeq_epi8(xmm0, xmm0); \
+			ZEND_ASSERT(size >= 64 && ((size & 0x3f) == 0)); \
+			do { \
+				_mm_storeu_si128((__m128i*)p, xmm0); \
+				_mm_storeu_si128((__m128i*)(p+16), xmm0); \
+				_mm_storeu_si128((__m128i*)(p+32), xmm0); \
+				_mm_storeu_si128((__m128i*)(p+48), xmm0); \
+				p += 64; \
+				size -= 64; \
+			} while (size != 0); \
+		} \
 	} while (0)
 #else
 # define HT_HASH_RESET(ht) \
