--- src/cpu/cpu_arm.c.orig	2020-07-02 18:19:46 UTC
+++ src/cpu/cpu_arm.c
@@ -22,7 +22,9 @@
 
 #include <config.h>
 #if defined(__aarch64__)
-# include <asm/hwcap.h>
+# if defined(__linux__)
+#  include <asm/hwcap.h>
+# endif
 # include <sys/auxv.h>
 #endif
 
@@ -518,11 +520,13 @@ virCPUarmCpuDataFromRegs(virCPUarmData *data)
     int cpu_feature_index = 0;
     size_t i;
 
+#if defined(__linux__)
     if (!(getauxval(AT_HWCAP) & HWCAP_CPUID)) {
         virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                        _("CPUID registers unavailable"));
             return -1;
     }
+#endif
 
     /* read the cpuid data from MIDR_EL1 register */
     asm("mrs %0, MIDR_EL1" : "=r" (cpuid));
@@ -533,7 +537,11 @@ virCPUarmCpuDataFromRegs(virCPUarmData *data)
     /* parse the coresponding vendor_id bits */
     data->vendor_id = (cpuid >> 24) & 0xff;
 
+#if defined(__linux__)
     hwcaps = getauxval(AT_HWCAP);
+#elif defined(__FreeBSD__)
+    elf_aux_info(AT_HWCAP, &hwcaps, sizeof(u_long));
+#endif
     VIR_DEBUG("CPU flags read from register:  0x%016lx", hwcaps);
 
     features = g_new0(char *, MAX_CPU_FLAGS + 1);
