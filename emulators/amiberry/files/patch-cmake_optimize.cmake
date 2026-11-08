--- cmake/optimize.cmake.orig	2026-10-04 18:52:13 UTC
+++ cmake/optimize.cmake
@@ -12,7 +12,7 @@ if(CMAKE_C_COMPILER_ID MATCHES "Clang")
     )
 
     if(CLANG_TARGET_CPU)
-        set(OPTIMIZED_FLAGS "-mcpu=${CLANG_TARGET_CPU}")
+        set(OPTIMIZED_FLAGS "-mtune=${CLANG_TARGET_CPU}")
         message(STATUS "Applied Clang optimization flags: ${OPTIMIZED_FLAGS}")
     else()
         message(WARNING "Could not extract Clang optimization flags")
