--- thirdparty/cpuid/src/cpuid/cpuinfo.cpp.orig	2021-09-23 02:16:22 UTC
+++ thirdparty/cpuid/src/cpuid/cpuinfo.cpp
@@ -16,7 +16,7 @@
     #include "detail/init_msvc_arm.hpp"
 #elif defined(PLATFORM_CLANG_ARM) && defined(PLATFORM_IOS)
     #include "detail/init_ios_clang_arm.hpp"
-#elif defined(PLATFORM_GCC_COMPATIBLE_ARM) && defined(PLATFORM_LINUX)
+#elif defined(PLATFORM_GCC_COMPATIBLE_ARM) && (defined(PLATFORM_LINUX) || defined(PLATFORM_FREEBSD))
     #include "detail/init_linux_gcc_arm.hpp"
 #else
     #include "detail/init_unknown.hpp"
