--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
@@ -32,6 +32,50 @@
 #include <machine/elf.h>
 #endif
 
+#ifndef HWCAP_ASIMD
+#define HWCAP_ASIMD (1<<1)
+#endif
+
+#ifndef HWCAP_AES
+#define HWCAP_AES   (1<<3)
+#endif
+
+#ifndef HWCAP_PMULL
+#define HWCAP_PMULL (1<<4)
+#endif
+
+#ifndef HWCAP_SHA1
+#define HWCAP_SHA1  (1<<5)
+#endif
+
+#ifndef HWCAP_SHA2
+#define HWCAP_SHA2  (1<<6)
+#endif
+
+#ifndef HWCAP_CRC32
+#define HWCAP_CRC32 (1<<7)
+#endif
+
+#ifndef HWCAP_ATOMICS
+#define HWCAP_ATOMICS (1<<8)
+#endif
+
+#ifndef ID_AA64PFR0_AdvSIMD_SHIFT
+#define ID_AA64PFR0_AdvSIMD_SHIFT 20
+#endif
+
+#ifndef ID_AA64PFR0_AdvSIMD
+#define ID_AA64PFR0_AdvSIMD(x) ((x) & (UL(0xf) << ID_AA64PFR0_AdvSIMD_SHIFT))
+#endif
+
+#ifndef ID_AA64PFR0_AdvSIMD_IMPL
+#define ID_AA64PFR0_AdvSIMD_IMPL (UL(0x0) << ID_AA64PFR0_AdvSIMD_SHIFT)
+#endif
+
+#ifndef ID_AA64PFR0_AdvSIMD_HP
+#define ID_AA64PFR0_AdvSIMD_HP (UL(0x1) << ID_AA64PFR0_AdvSIMD_SHIFT)
+#endif
+
 #define	CPU_IMPL_ARM		0x41
 #define	CPU_IMPL_BROADCOM	0x42
 #define	CPU_IMPL_CAVIUM		0x43
@@ -113,6 +157,7 @@
 #define	CPU_PART(midr)	(((midr) >> 4) & 0xfff)
 #define	CPU_VAR(midr)	(((midr) >> 20) & 0xf)
 #define	CPU_REV(midr)	(((midr) >> 0) & 0xf)
+#define UL(x)   UINT64_C(x)
 
 struct cpu_desc {
 	u_int		cpu_impl;
