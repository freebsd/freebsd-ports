--- libraries/lzma/C/CpuArch.c.orig	2026-09-27 08:20:17 UTC
+++ libraries/lzma/C/CpuArch.c
@@ -766,10 +766,21 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 
 #ifdef USE_HWCAP
 
+#if defined(__FreeBSD__)
+static unsigned long MY_getauxval(int aux)
+{
+  unsigned long val;
+  if (elf_aux_info(aux, &val, sizeof(val)))
+    return 0;
+  return val;
+}
+#else
+#define MY_getauxval  getauxval
 #include <asm/hwcap.h>
+#endif
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
-  BoolInt CPU_IsSupported_ ## name1() { return (getauxval(AT_HWCAP)  & (HWCAP_  ## name2)) ? 1 : 0; }
+  BoolInt CPU_IsSupported_ ## name1() { return (MY_getauxval(AT_HWCAP)  & (HWCAP_  ## name2)) ? 1 : 0; }
 
 #ifdef MY_CPU_ARM64
   #define MY_HWCAP_CHECK_FUNC(name) \
@@ -778,7 +789,7 @@ BoolInt CPU_IsSupported_AES (void) { return APPLE_CRYP
 // MY_HWCAP_CHECK_FUNC (ASIMD)
 #elif defined(MY_CPU_ARM)
   #define MY_HWCAP_CHECK_FUNC(name) \
-  BoolInt CPU_IsSupported_ ## name() { return (getauxval(AT_HWCAP2) & (HWCAP2_ ## name)) ? 1 : 0; }
+  BoolInt CPU_IsSupported_ ## name() { return (MY_getauxval(AT_HWCAP2) & (HWCAP2_ ## name)) ? 1 : 0; }
   MY_HWCAP_CHECK_FUNC_2(NEON, NEON)
 #endif
 
