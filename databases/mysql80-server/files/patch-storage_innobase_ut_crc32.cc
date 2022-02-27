--- storage/innobase/ut/crc32.cc.orig	2021-12-17 17:07:27 UTC
+++ storage/innobase/ut/crc32.cc
@@ -111,7 +111,9 @@ external tools. */
 #endif /* CRC32_ARM64 */
 
 #ifdef CRC32_ARM64_DEFAULT
+#ifndef __FreeBSD__
 #include <asm/hwcap.h>
+#endif
 #include <sys/auxv.h>
 #endif /* CRC32_ARM64_DEFAULT */
 
@@ -360,8 +362,25 @@ bool can_use_poly_mul() { return true; }
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
+  return capabilities & HWCAP_CRC32;
+}
+#else
 bool can_use_crc32() { return getauxval(AT_HWCAP) & HWCAP_CRC32; }
 bool can_use_poly_mul() { return getauxval(AT_HWCAP) & HWCAP_PMULL; }
+#endif
 #endif /* CRC32_ARM64_DEFAULT */
 
 /** A helper template to statically unroll a loop with a fixed number of
@@ -470,25 +489,39 @@ uint64_t crc32_impl::update(uint64_t crc, uint64_t dat
 
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
@@ -534,7 +567,11 @@ static inline uint64_t less_significant_half_of_poly12
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
@@ -777,7 +814,11 @@ MY_ATTRIBUTE((target("sse4.2,pclmul"), flatten))
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
@@ -797,7 +838,11 @@ MY_ATTRIBUTE((target("sse4.2"), flatten))
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
