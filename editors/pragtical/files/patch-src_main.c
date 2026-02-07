--- src/main.c.orig	2024-04-18 20:31:07 UTC
+++ src/main.c
@@ -101,6 +101,10 @@ void set_macos_bundle_resources(lua_State *L);
     #define ARCH_PROCESSOR "aarch64"
   #elif defined(__arm__) || defined(_M_ARM)
     #define ARCH_PROCESSOR "arm"
+  #elif defined(__powerpc64__)
+    #define ARCH_PROCESSOR "ppc64"
+  #elif defined(__powerpc__)
+    #define ARCH_PROCESSOR "ppc"
   #endif
 
   #if _WIN32
