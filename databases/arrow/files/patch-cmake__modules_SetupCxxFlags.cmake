--- cmake_modules/SetupCxxFlags.cmake.orig	2026-04-14 14:21:10 UTC
+++ cmake_modules/SetupCxxFlags.cmake
@@ -32,7 +32,7 @@ if(NOT DEFINED ARROW_CPU_FLAG)
     set(ARROW_CPU_FLAG "aarch32")
   elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|ARM64|arm64|armv")
     set(ARROW_CPU_FLAG "aarch64")
-  elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc|ppc")
+  elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc|powerpc64|ppc")
     set(ARROW_CPU_FLAG "ppc")
   elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "s390x")
     set(ARROW_CPU_FLAG "s390x")
