--- util/crc32c_arm64.cc.orig	2021-10-10 13:50:13 UTC
+++ util/crc32c_arm64.cc
@@ -5,9 +5,11 @@
 
 #include "util/crc32c_arm64.h"
 
-#if defined(__linux__) && defined(HAVE_ARM64_CRC)
+#if (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
 
+#if !defined(__FreeBSD__)
 #include <asm/hwcap.h>
+#endif
 #ifdef ROCKSDB_AUXV_GETAUXVAL_PRESENT
 #include <sys/auxv.h>
 #endif
@@ -37,7 +39,14 @@
 
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
