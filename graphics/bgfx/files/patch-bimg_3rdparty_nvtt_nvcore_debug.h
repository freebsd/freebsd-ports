--- bimg/3rdparty/nvtt/nvcore/debug.h.orig	2023-11-23 17:42:13 UTC
+++ bimg/3rdparty/nvtt/nvcore/debug.h
@@ -166,7 +166,7 @@ NVCORE_API void NV_CDECL nvDebugPrint( const char *msg
 namespace nv
 {
     inline bool isValidPtr(const void * ptr) {
-    #if NV_CPU_X86_64 || NV_CPU_AARCH64
+    #if defined(__LP64__)
         if (ptr == NULL) return true;
         if (reinterpret_cast<uint64>(ptr) < 0x10000ULL) return false;
         if (reinterpret_cast<uint64>(ptr) >= 0x000007FFFFFEFFFFULL) return false;
