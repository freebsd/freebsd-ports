--- cmake/TargetArchitecture.cmake.orig	2025-02-03 19:33:59 UTC
+++ cmake/TargetArchitecture.cmake
@@ -1,7 +1,7 @@
 # This script detects supported target architectures and configures test flags
 # accordingly
 
-if (${CMAKE_SYSTEM_PROCESSOR} MATCHES x86|x64)
+if (${CMAKE_SYSTEM_PROCESSOR} MATCHES x86|x64|amd64)
 	set(PIONEER_TARGET_INTEL ON)
 endif()
 
