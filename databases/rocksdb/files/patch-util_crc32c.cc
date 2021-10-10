--- util/crc32c.cc.orig	2021-10-10 17:19:37 UTC
+++ util/crc32c.cc
@@ -463,6 +463,21 @@ static int arch_ppc_probe(void) {
 
   return arch_ppc_crc32;
 }
+#elif __FreeBSD__
+#include <machine/cpu.h>
+#include <sys/auxv.h>
+#include <sys/elf_common.h>
+static int arch_ppc_probe(void) {
+  unsigned long cpufeatures;
+  arch_ppc_crc32 = 0;
+
+#if defined(__powerpc64__)
+  elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures));
+  if (cpufeatures & PPC_FEATURE2_HAS_VEC_CRYPTO) arch_ppc_crc32 = 1;
+#endif  /* __powerpc64__ */
+
+  return arch_ppc_crc32;
+}
 #endif  // __linux__
 
 static bool isAltiVec() {
@@ -474,7 +489,7 @@ static bool isAltiVec() {
 }
 #endif
 
-#if defined(__linux__) && defined(HAVE_ARM64_CRC)
+#if (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
 uint32_t ExtendARMImpl(uint32_t crc, const char *buf, size_t size) {
   return crc32c_arm64(crc, (const unsigned char *)buf, size);
 }
@@ -494,7 +509,7 @@ std::string IsFastCrc32Supported() {
   has_fast_crc = false;
   arch = "PPC";
 #endif
-#elif defined(__linux__) && defined(HAVE_ARM64_CRC)
+#elif (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
   if (crc32c_runtime_check()) {
     has_fast_crc = true;
     arch = "Arm64";
@@ -1226,7 +1241,7 @@ uint32_t crc32c_3way(uint32_t crc, const char* buf, si
 static inline Function Choose_Extend() {
 #ifdef HAVE_POWER8
   return isAltiVec() ? ExtendPPCImpl : ExtendImpl<Slow_CRC32>;
-#elif defined(__linux__) && defined(HAVE_ARM64_CRC)
+#elif (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
   if(crc32c_runtime_check()) {
     return ExtendARMImpl;
   } else {
