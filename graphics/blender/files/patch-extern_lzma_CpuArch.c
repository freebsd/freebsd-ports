--- extern/lzma/CpuArch.c.orig	2024-09-26 11:32:05 UTC
+++ extern/lzma/CpuArch.c
@@ -766,6 +766,25 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 
 #ifdef USE_HWCAP
 
+#ifdef __FreeBSD__
+
+  #define MY_HWCAP_CHECK_FUNC_3(name1, name2, at) \
+  BoolInt CPU_IsSupported_ ## name1() { \
+    unsigned long vec = 0; \
+    elf_aux_info(AT_ ## at, &vec, sizeof(vec)); \
+    return (vec & (at ## _ ## name2)) ? 1 : 0; \
+  }
+
+#ifdef MY_CPU_ARM64
+  #define MY_HWCAP_CHECK_FUNC(name) MY_HWCAP_CHECK_FUNC_3(name, name, HWCAP)
+  MY_HWCAP_CHECK_FUNC_3(NEON, ASIMD, HWCAP)
+#elif defined(MY_CPU_ARM)
+  #define MY_HWCAP_CHECK_FUNC(name) MY_HWCAP_CHECK_FUNC_3(name, name, HWCAP2)
+  MY_HWCAP_CHECK_FUNC_3(NEON, NEON, HWCAP)
+#endif
+
+#else // __FreeBSD__
+
 #include <asm/hwcap.h>
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
@@ -781,6 +800,8 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
   BoolInt CPU_IsSupported_ ## name() { return (getauxval(AT_HWCAP2) & (HWCAP2_ ## name)) ? 1 : 0; }
   MY_HWCAP_CHECK_FUNC_2(NEON, NEON)
 #endif
+
+#endif // __FreeBSD__
 
 #else // USE_HWCAP
 
