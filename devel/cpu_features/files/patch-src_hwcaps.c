--- src/hwcaps.c.orig	2023-09-14 12:15:33 UTC
+++ src/hwcaps.c
@@ -55,12 +55,16 @@ const char* CpuFeatures_GetBasePlatformPointer(void);
 // Implementation of GetElfHwcapFromGetauxval
 ////////////////////////////////////////////////////////////////////////////////
 
-#define AT_HWCAP 16
-#define AT_HWCAP2 26
-#define AT_PLATFORM 15
-#define AT_BASE_PLATFORM 24
+#if defined(CPU_FEATURES_OS_FREEBSD)
+#include <sys/auxv.h>
+static unsigned long GetElfHwcapFromGetauxval(uint32_t hwcap_type) {
+  unsigned long val = 0;
 
-#if defined(HAVE_STRONG_GETAUXVAL)
+  elf_aux_info(hwcap_type, &val, sizeof val);
+
+  return val;
+}
+#elif defined(HAVE_STRONG_GETAUXVAL)
 #include <sys/auxv.h>
 static unsigned long GetElfHwcapFromGetauxval(uint32_t hwcap_type) {
   return getauxval(hwcap_type);
@@ -159,11 +163,19 @@ const char *CpuFeatures_GetPlatformPointer(void) {
 }
 
 const char *CpuFeatures_GetPlatformPointer(void) {
+#ifdef AT_PLATFORM
   return (const char *)GetHardwareCapabilitiesFor(AT_PLATFORM);
+#else
+  return NULL;
+#endif
 }
 
 const char *CpuFeatures_GetBasePlatformPointer(void) {
+#ifdef AT_BASE_PLATFORM
   return (const char *)GetHardwareCapabilitiesFor(AT_BASE_PLATFORM);
+#else
+  return NULL;
+#endif
 }
 
 #endif  // CPU_FEATURES_TEST
