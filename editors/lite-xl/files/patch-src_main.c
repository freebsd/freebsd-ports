--- src/main.c.orig	2022-12-29 02:03:36 UTC
+++ src/main.c
@@ -99,6 +99,10 @@ void set_macos_bundle_resources(lua_State *L);
     #define ARCH_PROCESSOR "aarch64"
   #elif defined(__arm__) || defined(_M_ARM)
     #define ARCH_PROCESSOR "arm"
+  #elif defined(__powerpc64__)
+    #define ARCH_PROCESSOR "ppc64"
+  #elif defined(__powerpc__)
+    #define ARCH_PROCESSOR "ppc"
   #endif
 
   #if _WIN32
