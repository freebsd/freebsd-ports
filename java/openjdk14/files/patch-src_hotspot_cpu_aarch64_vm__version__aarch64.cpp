--- src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
+++ src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
@@ -35,6 +35,7 @@
 
 #include OS_HEADER_INLINE(os)
 
+#ifndef BUILTIN_SIM
 #if defined (__linux__)
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
