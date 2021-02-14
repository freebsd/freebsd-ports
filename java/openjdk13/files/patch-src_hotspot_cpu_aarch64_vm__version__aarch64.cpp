--- src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
+++ src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
@@ -34,8 +34,12 @@
 
 #include OS_HEADER_INLINE(os)
 
+#if defined(__linux__)
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
+#elif defined(__FreeBSD__)
+#include <machine/elf.h>
+#endif
 
 #ifndef HWCAP_ASIMD
 #define HWCAP_ASIMD (1<<1)
