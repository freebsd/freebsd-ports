--- src/external/cpuid/src/cpuid/detail/init_linux_gcc_arm.hpp.orig	2024-12-29 13:01:01 UTC
+++ src/external/cpuid/src/cpuid/detail/init_linux_gcc_arm.hpp
@@ -11,7 +11,11 @@
 
 #include <elf.h>
 #include <fcntl.h>
+#ifdef __FreeBSD__
+#include <sys/auxv.h>
+#else
 #include <linux/auxvec.h>
+#endif
 #include <unistd.h>
 
 #include "cpuinfo_impl.hpp"
@@ -28,6 +32,13 @@ void init_cpuinfo(cpuinfo::impl& info)
     // (64-bit ARM). Note that /proc/cpuinfo will display "asimd" instead of
     // "neon" in the Features list on a 64-bit ARM CPU.
     info.m_has_neon = true;
+#elif defined(__FreeBSD__)
+    // armv7 FreeBSD
+    long hwcap = 0;
+
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+
+    info.m_has_neon = hwcap & HWCAP_NEON;
 #else
     // Runtime detection of NEON is necessary on 32-bit ARM CPUs
     //
