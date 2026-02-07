--- cmake_modules/SetupCxxFlags.cmake.orig	2023-08-17 08:05:04 UTC
+++ cmake_modules/SetupCxxFlags.cmake
@@ -30,7 +30,7 @@ if(NOT DEFINED ARROW_CPU_FLAG)
     set(ARROW_CPU_FLAG "aarch64")
   elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm$|armv[4-7]")
     set(ARROW_CPU_FLAG "aarch32")
-  elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc|ppc")
+  elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc|powerpc64|ppc")
     set(ARROW_CPU_FLAG "ppc")
   elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "s390x")
     set(ARROW_CPU_FLAG "s390x")
