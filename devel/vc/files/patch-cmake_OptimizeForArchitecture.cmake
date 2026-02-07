--- cmake/OptimizeForArchitecture.cmake.orig	2022-03-30 13:11:00 UTC
+++ cmake/OptimizeForArchitecture.cmake
@@ -205,7 +205,7 @@ macro(AutodetectHostArchitecture)
 endmacro()
 
 macro(OptimizeForArchitecture)
-   if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "(x86|AMD64)")
+   if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "(i[3-6]86|x86|AMD64|amd64)")
       OptimizeForArchitectureX86()
    else()
       message(STATUS "No support for auto-detection of the target instruction set/extension")
