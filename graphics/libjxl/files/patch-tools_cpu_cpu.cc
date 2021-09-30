--- tools/cpu/cpu.cc.orig	2021-09-30 15:38:45 UTC
+++ tools/cpu/cpu.cc
@@ -19,7 +19,9 @@
 #endif
 
 #if JXL_ARCH_PPC
-#include <sys/platform/ppc.h>  // __ppc_get_timebase_freq
+#if linux
+#include <sys/platform/ppc.h>  // NOLINT __ppc_get_timebase_freq
+#endif
 #endif
 
 #if JXL_ARCH_ARM
