--- src/nvcore/Debug.h.orig	2020-08-24 06:27:21 UTC
+++ src/nvcore/Debug.h
@@ -166,7 +166,7 @@ namespace nv
 namespace nv
 {
     inline bool isValidPtr(const void * ptr) {
-    #if NV_CPU_X86_64 || POSH_CPU_PPC64 || NV_CPU_AARCH64
+    #if NV_CPU_X86_64 || POSH_CPU_PPC64 || NV_CPU_ARM_64
         if (ptr == NULL) return true;
         if (reinterpret_cast<uint64>(ptr) < 0x10000ULL) return false;
         if (reinterpret_cast<uint64>(ptr) >= 0x000007FFFFFEFFFFULL) return false;
