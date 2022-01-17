--- cmake/tools.cmake.orig	2021-12-26 09:29:33 UTC
+++ cmake/tools.cmake
@@ -40,7 +40,7 @@ elseif (COMPILER_CLANG)
             set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fchar8_t")
         endif ()
     else ()
-        set (CLANG_MINIMUM_VERSION 12)
+        set (CLANG_MINIMUM_VERSION 11)
         if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${CLANG_MINIMUM_VERSION})
             message (FATAL_ERROR "Clang version must be at least ${CLANG_MINIMUM_VERSION}.")
         endif ()
