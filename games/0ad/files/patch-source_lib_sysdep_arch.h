--- source/lib/sysdep/arch.h.orig	2021-02-28 23:45:13 UTC
+++ source/lib/sysdep/arch.h
@@ -76,9 +76,14 @@
 #else
 # define ARCH_E2K 0
 #endif
+#if defined(__PPC64__)
+# define ARCH_PPC64 1
+#else
+# define ARCH_PPC64 0
+#endif
 
 // ensure exactly one architecture has been detected
-#if (ARCH_IA32+ARCH_IA64+ARCH_AMD64+ARCH_ALPHA+ARCH_ARM+ARCH_AARCH64+ARCH_MIPS+ARCH_E2K) != 1
+#if (ARCH_IA32+ARCH_IA64+ARCH_AMD64+ARCH_ALPHA+ARCH_ARM+ARCH_AARCH64+ARCH_MIPS+ARCH_E2K+ARCH_PPC64) != 1
 # error "architecture not correctly detected (either none or multiple ARCH_* defined)"
 #endif
 
