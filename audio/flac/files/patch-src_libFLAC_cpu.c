--- src/libFLAC/cpu.c.orig	2018-08-20 08:17:21 UTC
+++ src/libFLAC/cpu.c
@@ -53,7 +53,7 @@
 #define dfprintf(file, format, ...)
 #endif
 
-#if defined FLAC__CPU_PPC
+#if defined(HAVE_SYS_AUXV_H)
 #include <sys/auxv.h>
 #endif
 
@@ -236,7 +236,10 @@ x86_cpu_info (FLAC__CPUInfo *info)
 static void
 ppc_cpu_info (FLAC__CPUInfo *info)
 {
-#if defined FLAC__CPU_PPC
+	info->ppc.arch_2_07 = false;
+	info->ppc.arch_3_00 = false;
+
+#if defined(FLAC__CPU_PPC)
 #ifndef PPC_FEATURE2_ARCH_3_00
 #define PPC_FEATURE2_ARCH_3_00		0x00800000
 #endif
@@ -245,14 +248,21 @@ ppc_cpu_info (FLAC__CPUInfo *info)
 #define PPC_FEATURE2_ARCH_2_07		0x80000000
 #endif
 
+#if defined(HAVE_GETAUXVAL)
 	if (getauxval(AT_HWCAP2) & PPC_FEATURE2_ARCH_3_00) {
 		info->ppc.arch_3_00 = true;
 	} else if (getauxval(AT_HWCAP2) & PPC_FEATURE2_ARCH_2_07) {
 		info->ppc.arch_2_07 = true;
 	}
-#else
-	info->ppc.arch_2_07 = false;
-	info->ppc.arch_3_00 = false;
+#elif defined(HAVE_ELF_AUX_INFO)
+	long hwcaps;
+	elf_aux_info(AT_HWCAP2, &hwcaps, sizeof(hwcaps));
+	if (hwcaps & PPC_FEATURE2_ARCH_3_00) {
+		info->ppc.arch_3_00 = true;
+	} else if (hwcaps & PPC_FEATURE2_ARCH_2_07) {
+		info->ppc.arch_2_07 = true;
+	}
+#endif
 #endif
 }
 
