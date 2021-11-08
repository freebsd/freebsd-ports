--- contrib/rocksdb/util/crc32c_arm64.cc.orig	2021-05-13 00:21:57.000000000 +0200
+++ contrib/rocksdb/util/crc32c_arm64.cc	2000-01-01 02:32:56.500264000 +0100
@@ -5,9 +5,11 @@
 
 #include "util/crc32c_arm64.h"
 
-#if defined(__linux__) && defined(HAVE_ARM64_CRC)
+#if (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
 
+#if defined(__linux__)
 #include <asm/hwcap.h>
+#endif // linux
 #ifdef ROCKSDB_AUXV_GETAUXVAL_PRESENT
 #include <sys/auxv.h>
 #endif
@@ -42,7 +44,14 @@ extern bool pmull_runtime_flag;
 
 uint32_t crc32c_runtime_check(void) {
 #ifdef ROCKSDB_AUXV_GETAUXVAL_PRESENT
+#if defined(__FreeBSD__)
+  uint64_t auxv;
+  int result = elf_aux_info(AT_HWCAP, &auxv, sizeof auxv);
+  if (result != 0)
+    return 0;
+#else
   uint64_t auxv = getauxval(AT_HWCAP);
+#endif
   return (auxv & HWCAP_CRC32) != 0;
 #else
   return 0;
@@ -51,7 +60,14 @@ uint32_t crc32c_runtime_check(void) {
 
 bool crc32c_pmull_runtime_check(void) {
 #ifdef ROCKSDB_AUXV_GETAUXVAL_PRESENT
+#if defined(__FreeBSD__)
+  uint64_t auxv;
+  int result = elf_aux_info(AT_HWCAP, &auxv, sizeof auxv);
+  if (result != 0)
+    return 0;
+#else
   uint64_t auxv = getauxval(AT_HWCAP);
+#endif
   return (auxv & HWCAP_PMULL) != 0;
 #else
   return false;
