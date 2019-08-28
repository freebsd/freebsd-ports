--- src/libFLAC/cpu.c.orig	2019-08-15 00:05:19 UTC
+++ src/libFLAC/cpu.c
@@ -245,11 +245,21 @@ ppc_cpu_info (FLAC__CPUInfo *info)
 #define PPC_FEATURE2_ARCH_2_07		0x80000000
 #endif
 
+#ifdef __linux__
 	if (getauxval(AT_HWCAP2) & PPC_FEATURE2_ARCH_3_00) {
 		info->ppc.arch_3_00 = true;
 	} else if (getauxval(AT_HWCAP2) & PPC_FEATURE2_ARCH_2_07) {
 		info->ppc.arch_2_07 = true;
 	}
+#elif defined(__FreeBSD__)
+	long hwcaps;
+	elf_aux_info(AT_HWCAP2, &hwcaps, sizeof(hwcaps));
+	if (hwcaps & PPC_FEATURE2_ARCH_3_00) {
+		info->ppc.arch_3_00 = true;
+	} else if (hwcaps & PPC_FEATURE2_ARCH_2_07) {
+		info->ppc.arch_2_07 = true;
+	}
+#endif
 #else
 	info->ppc.arch_2_07 = false;
 	info->ppc.arch_3_00 = false;
