--- 3rdparty/lzma/C/CpuArch.c.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/C/CpuArch.c
@@ -417,6 +417,31 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 
 #include <sys/auxv.h>
 
+#if defined(__FreeBSD__)
+static unsigned long get_hwcap(int aux) {
+  unsigned long hwcap;
+  if (elf_aux_info(aux, &hwcap, sizeof hwcap) != 0) {
+        return 0;
+  }
+  return hwcap;
+}
+
+#ifdef MY_CPU_ARM64
+BoolInt CPU_IsSupported_CRC32(void) { return get_hwcap(AT_HWCAP) & HWCAP_CRC32; }
+BoolInt CPU_IsSupported_NEON(void) { return 1; }
+BoolInt CPU_IsSupported_SHA1(void){ return get_hwcap(AT_HWCAP) & HWCAP_SHA1; }
+BoolInt CPU_IsSupported_SHA2(void) { return get_hwcap(AT_HWCAP) & HWCAP_SHA2; }
+BoolInt CPU_IsSupported_AES(void) { return get_hwcap(AT_HWCAP) & HWCAP_AES; }
+#else /* MY_CPU_ARM */
+BoolInt CPU_IsSupported_CRC32(void) { return get_hwcap(AT_HWCAP2) & HWCAP2_CRC32; }
+BoolInt CPU_IsSupported_NEON(void) { return get_hwcap(AT_HWCAP) & HWCAP_NEON; }
+BoolInt CPU_IsSupported_SHA1(void){ return get_hwcap(AT_HWCAP2) & HWCAP2_SHA1; }
+BoolInt CPU_IsSupported_SHA2(void) { return get_hwcap(AT_HWCAP2) & HWCAP2_SHA2; }
+BoolInt CPU_IsSupported_AES(void) { return get_hwcap(AT_HWCAP2) & HWCAP2_AES; }
+#endif
+
+#else // __FreeBSD__
+
 #define USE_HWCAP
 
 #ifdef USE_HWCAP
@@ -450,6 +475,7 @@ MY_HWCAP_CHECK_FUNC (SHA1)
 MY_HWCAP_CHECK_FUNC (SHA2)
 MY_HWCAP_CHECK_FUNC (AES)
 
+#endif // FreeBSD
 #endif // __APPLE__
 #endif // _WIN32
 
