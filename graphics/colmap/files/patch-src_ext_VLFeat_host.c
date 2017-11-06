vlfeat: don't try to use CPUID on non-x86

--- src/ext/VLFeat/host.c.orig	2017-06-15 14:32:01 UTC
+++ src/ext/VLFeat/host.c
@@ -441,6 +441,7 @@ _vl_cpuid (vl_int32* info, int function)
 
 #endif
 
+#if defined(VL_ARCH_IX86) || defined(VL_ARCH_X64) || defined(VL_ARCH_IA64)
 void
 _vl_x86cpu_info_init (VlX86CpuInfo *self)
 {
@@ -487,6 +488,7 @@ _vl_x86cpu_info_to_string_copy (VlX86CpuInfo const *se
   }
   return string ;
 }
+#endif
 
 /** ------------------------------------------------------------------
  ** @brief Human readable static library configuration
