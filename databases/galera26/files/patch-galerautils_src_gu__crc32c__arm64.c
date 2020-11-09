--- galerautils/src/gu_crc32c_arm64.c.orig	2020-10-27 20:24:41 UTC
+++ galerautils/src/gu_crc32c_arm64.c
@@ -74,7 +74,13 @@ gu_crc32c_arm64(gu_crc32c_t state, const void* data, s
 gu_crc32c_func_t
 gu_crc32c_hardware()
 {
+#if defined(__linux__)
     unsigned long int const hwcaps = getauxval(AT_HWCAP);
+#endif
+#if defined(__FreeBSD__)
+    unsigned long hwcaps;
+    elf_aux_info(AT_HWCAP, &hwcaps, sizeof(hwcaps));
+#endif
     if (hwcaps & HWCAP_CRC32)
     {
         gu_info ("CRC-32C: using hardware acceleration.");
