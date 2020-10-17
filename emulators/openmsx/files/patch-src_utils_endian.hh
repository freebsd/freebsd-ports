--- src/utils/endian.hh.orig	2020-08-25 21:16:08 UTC
+++ src/utils/endian.hh
@@ -9,23 +9,23 @@
 namespace Endian {
 
 // Reverse bytes in a 16-bit number: 0x1234 becomes 0x3412
-[[nodiscard]] static inline uint16_t bswap16(uint16_t x)
+[[nodiscard]] static inline uint16_t byteswap16(uint16_t x)
 {
 	// This sequence generates 'optimal' code on a wide range of gcc/clang
 	// versions (a single rotate instruction on x86). The newer compiler
 	// versions also do 'the right thing' for the simpler expression below.
-	// Those newer compilers also support __builtin_bswap16() but that
+	// Those newer compilers also support __builtin_byteswap16() but that
 	// doesn't generate better code (and is less portable).
 	return ((x & 0x00FF) << 8) | ((x & 0xFF00) >> 8);
 	//return (x << 8) | (x >> 8);
 }
 
 // Reverse bytes in a 32-bit number: 0x12345678 becomes 0x78563412
-[[nodiscard]] static inline uint32_t bswap32(uint32_t x)
+[[nodiscard]] static inline uint32_t byteswap32(uint32_t x)
 {
 #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3))
 	// Starting from gcc-4.3 there's a builtin function for this.
-	// E.g. on x86 this is translated to a single 'bswap' instruction.
+	// E.g. on x86 this is translated to a single 'byteswap' instruction.
 	return __builtin_bswap32(x);
 #else
 	return  (x << 24)               |
@@ -36,22 +36,22 @@ namespace Endian {
 }
 
 // Reverse bytes in a 64-bit value: 0x1122334455667788 becomes 0x8877665544332211
-[[nodiscard]] static inline uint64_t bswap64(uint64_t x)
+[[nodiscard]] static inline uint64_t byteswap64(uint64_t x)
 {
 #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3))
 	// Starting from gcc-4.3 there's a builtin function for this.
-	// E.g. on x86 this is translated to a single 'bswap' instruction.
+	// E.g. on x86 this is translated to a single 'byteswap' instruction.
 	return __builtin_bswap64(x);
 #else
-	return (uint64_t(bswap32(x >>  0)) << 32) |
-	       (uint64_t(bswap32(x >> 32)) <<  0);
+	return (uint64_t(byteswap32(x >>  0)) << 32) |
+	       (uint64_t(byteswap32(x >> 32)) <<  0);
 #endif
 }
 
-// Use overloading to get a (statically) polymorphic bswap() function.
-[[nodiscard]] static inline uint16_t bswap(uint16_t x) { return bswap16(x); }
-[[nodiscard]] static inline uint32_t bswap(uint32_t x) { return bswap32(x); }
-[[nodiscard]] static inline uint64_t bswap(uint64_t x) { return bswap64(x); }
+// Use overloading to get a (statically) polymorphic byteswap() function.
+[[nodiscard]] static inline uint16_t byteswap(uint16_t x) { return byteswap16(x); }
+[[nodiscard]] static inline uint32_t byteswap(uint32_t x) { return byteswap32(x); }
+[[nodiscard]] static inline uint64_t byteswap(uint64_t x) { return byteswap64(x); }
 
 
 // Identity operator, simply returns the given value.
@@ -61,7 +61,7 @@ struct Ident {
 
 // Byte-swap operator, swap bytes in the given value (16 or 32 bit).
 struct BSwap {
-	template <typename T> [[nodiscard]] inline T operator()(T t) const { return bswap(t); }
+	template <typename T> [[nodiscard]] inline T operator()(T t) const { return byteswap(t); }
 };
 
 // Helper class that stores a value and allows to read/write that value. Though
@@ -165,7 +165,7 @@ static inline void writeL32(void* p, uint32_t x)
 
 template<bool SWAP, typename T> static ALWAYS_INLINE void write_UA(void* p, T x)
 {
-	if (SWAP) x = bswap(x);
+	if (SWAP) x = byteswap(x);
 	memcpy(p, &x, sizeof(x));
 }
 static ALWAYS_INLINE void write_UA_B16(void* p, uint16_t x)
@@ -197,7 +197,7 @@ template<bool SWAP, typename T> [[nodiscard]] static A
 {
 	T x;
 	memcpy(&x, p, sizeof(x));
-	if (SWAP) x = bswap(x);
+	if (SWAP) x = byteswap(x);
 	return x;
 }
 [[nodiscard]] static ALWAYS_INLINE uint16_t read_UA_B16(const void* p)
