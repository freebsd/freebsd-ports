--- src/external/ghc/filesystem.hpp.orig	2020-04-20 01:09:03 UTC
+++ src/external/ghc/filesystem.hpp
@@ -43,7 +43,7 @@
 #ifndef GHC_OS_DETECTED
 #if defined(__APPLE__) && defined(__MACH__)
 #define GHC_OS_MACOS
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define GHC_OS_LINUX
 #if defined(__ANDROID__)
 #define GHC_OS_ANDROID
