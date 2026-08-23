--- storage/innobase/ut/crc32.cc.orig	2024-07-12 19:15:25 UTC
+++ storage/innobase/ut/crc32.cc
@@ -333,8 +333,25 @@ bool can_use_poly_mul() { return true; }
 #endif /* CRC32_ARM64_APPLE */
 
 #ifdef CRC32_ARM64_DEFAULT
+#ifdef __FreeBSD__
+bool can_use_crc32() {
+  unsigned long capabilities;
+
+  if (elf_aux_info(AT_HWCAP, &capabilities, sizeof(unsigned long)))
+    return false;
+  return capabilities & HWCAP_CRC32;
+}
+bool can_use_poly_mul() {
+  unsigned long capabilities;
+
+  if (elf_aux_info(AT_HWCAP, &capabilities, sizeof(unsigned long)))
+    return false;
+  return capabilities & HWCAP_PMULL;
+}
+#else
 bool can_use_crc32() { return getauxval(AT_HWCAP) & HWCAP_CRC32; }
 bool can_use_poly_mul() { return getauxval(AT_HWCAP) & HWCAP_PMULL; }
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 
 /** A helper template to statically unroll a loop with a fixed number of
@@ -423,19 +440,19 @@ struct crc32_impl {
 };
 
 #ifdef CRC32_x86_64
-MY_ATTRIBUTE((target("sse4.2")))
+MY_ATTRIBUTE((target("crc32")))
 uint32_t crc32_impl::update(uint32_t crc, unsigned char data) {
   return _mm_crc32_u8(crc, data);
 }
-MY_ATTRIBUTE((target("sse4.2")))
+MY_ATTRIBUTE((target("crc32")))
 uint32_t crc32_impl::update(uint32_t crc, uint16_t data) {
   return _mm_crc32_u16(crc, data);
 }
-MY_ATTRIBUTE((target("sse4.2")))
+MY_ATTRIBUTE((target("crc32")))
 uint32_t crc32_impl::update(uint32_t crc, uint32_t data) {
   return _mm_crc32_u32(crc, data);
 }
-MY_ATTRIBUTE((target("sse4.2")))
+MY_ATTRIBUTE((target("crc32")))
 uint64_t crc32_impl::update(uint64_t crc, uint64_t data) {
   return _mm_crc32_u64(crc, data);
 }
@@ -443,25 +460,39 @@ uint64_t crc32_impl::update(uint64_t crc, uint64_t dat
 
 #ifdef CRC32_ARM64
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc")))
+#else
+MY_ATTRIBUTE((target("crc")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint32_t crc32_impl::update(uint32_t crc, unsigned char data) {
   return __crc32cb(crc, data);
 }
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint32_t crc32_impl::update(uint32_t crc, uint16_t data) {
   return __crc32ch(crc, data);
 }
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc")))
+#else
+MY_ATTRIBUTE((target("crc")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint32_t crc32_impl::update(uint32_t crc, uint32_t data) {
   return __crc32cw(crc, data);
 }
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc")))
+#else
+MY_ATTRIBUTE((target("crc")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint64_t crc32_impl::update(uint64_t crc, uint64_t data) {
   return (uint64_t)__crc32cd((uint32_t)crc, data);
@@ -478,7 +509,7 @@ template <uint32_t w>
 };
 #ifdef CRC32_x86_64
 template <uint32_t w>
-MY_ATTRIBUTE((target("sse4.2,pclmul")))
+MY_ATTRIBUTE((target("crc32,pclmul")))
 uint64_t use_pclmul::polynomial_mul_rev(uint32_t rev_u) {
   constexpr uint64_t flipped_w = flip_at_32(w);
   return _mm_cvtsi128_si64(_mm_clmulepi64_si128(
@@ -507,7 +538,11 @@ template <uint32_t w>
 }
 template <uint32_t w>
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crypto")))
+#else
+MY_ATTRIBUTE((target("crypto")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint64_t use_pclmul::polynomial_mul_rev(uint32_t rev_u) {
   constexpr uint64_t flipped_w = flip_at_32(w);
@@ -744,13 +779,17 @@ It's non-static so it can be unit-tested.
 @param[in]      len     data length
 @return CRC-32C (polynomial 0x11EDC6F41) */
 #ifdef CRC32_x86_64_DEFAULT
-MY_ATTRIBUTE((target("sse4.2,pclmul"), flatten))
+MY_ATTRIBUTE((target("crc32,pclmul"), flatten))
 #endif /* CRC32_x86_64_DEFAULT */
 #ifdef CRC32_ARM64_APPLE
 MY_ATTRIBUTE((flatten))
 #endif /* CRC32_ARM64_APPLE */
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc+crypto"), flatten))
+#else
+MY_ATTRIBUTE((target("crc,crypto")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint32_t crc32_using_pclmul(const byte *data, size_t len) {
   return crc32<use_pclmul>(0, data, len);
@@ -764,13 +803,17 @@ It's non-static so it can be unit-tested.
 @param[in]      len     data length
 @return CRC-32C (polynomial 0x11EDC6F41) */
 #ifdef CRC32_x86_64_DEFAULT
-MY_ATTRIBUTE((target("sse4.2"), flatten))
+MY_ATTRIBUTE((target("crc32"), flatten))
 #endif /* CRC32_x86_64_DEFAULT */
 #ifdef CRC32_ARM64_APPLE
 MY_ATTRIBUTE((flatten))
 #endif /* CRC32_ARM64_APPLE */
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __clang__
 MY_ATTRIBUTE((target("+crc"), flatten))
+#else
+MY_ATTRIBUTE((target("crc")))
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 uint32_t crc32_using_unrolled_loop_poly_mul(const byte *data, size_t len) {
   return crc32<use_unrolled_loop_poly_mul>(0, data, len);
