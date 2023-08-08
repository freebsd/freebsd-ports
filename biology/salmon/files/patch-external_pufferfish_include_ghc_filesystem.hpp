--- external/pufferfish/include/ghc/filesystem.hpp.orig	2021-11-22 21:10:29 UTC
+++ external/pufferfish/include/ghc/filesystem.hpp
@@ -50,6 +50,8 @@
 
 #if defined(__APPLE__) && defined(__MACH__)
 #define GHC_OS_MACOS
+#elif defined(__FreeBSD__)
+#define GHC_OS_FREEBSD
 #elif defined(__linux__)
 #define GHC_OS_LINUX
 #elif defined(_WIN64)
