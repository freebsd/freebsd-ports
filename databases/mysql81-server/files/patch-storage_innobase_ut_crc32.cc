--- storage/innobase/ut/crc32.cc.orig	2023-06-21 07:52:10 UTC
+++ storage/innobase/ut/crc32.cc
@@ -332,8 +332,25 @@ bool can_use_poly_mul() { return true; }
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
@@ -442,25 +459,39 @@ uint64_t crc32_impl::update(uint64_t crc, uint64_t dat
 
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
@@ -506,7 +537,11 @@ template <uint32_t w>
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
@@ -749,7 +784,11 @@ MY_ATTRIBUTE((flatten))
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
@@ -769,7 +808,11 @@ MY_ATTRIBUTE((flatten))
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
