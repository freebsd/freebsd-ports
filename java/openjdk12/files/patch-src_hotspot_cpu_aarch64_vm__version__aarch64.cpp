--- src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
+++ src/hotspot/cpu/aarch64/vm_version_aarch64.cpp
@@ -45,6 +45,10 @@
 #define getauxval(hwcap) 0
 #endif
 
+#ifndef HWCAP_ASIMD
+#define HWCAP_ASIMD (1<<1)
+#endif
+
 #ifndef HWCAP_AES
 #define HWCAP_AES   (1<<3)
 #endif
