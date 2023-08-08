--- src/bele.h.orig	2023-01-30 10:18:06 UTC
+++ src/bele.h
@@ -84,19 +84,6 @@ static forceinline unsigned bswap16(unsigned v) { retu
 static forceinline unsigned bswap32(unsigned v) { return (unsigned) _byteswap_ulong(v); }
 static forceinline upx_uint64_t bswap64(upx_uint64_t v) { return _byteswap_uint64(v); }
 
-#else
-
-static forceinline constexpr unsigned bswap16(unsigned v) {
-    // return __builtin_bswap16((upx_uint16_t) (v & 0xffff));
-    // return (unsigned) __builtin_bswap64((upx_uint64_t) v << 48);
-    return __builtin_bswap32(v << 16);
-}
-static forceinline constexpr unsigned bswap32(unsigned v) {
-    // return (unsigned) __builtin_bswap64((upx_uint64_t) v << 32);
-    return __builtin_bswap32(v);
-}
-static forceinline constexpr upx_uint64_t bswap64(upx_uint64_t v) { return __builtin_bswap64(v); }
-
 #endif
 
 static forceinline constexpr unsigned no_bswap16(unsigned v) {
