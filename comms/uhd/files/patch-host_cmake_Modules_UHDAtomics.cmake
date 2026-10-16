--- host/cmake/Modules/UHDAtomics.cmake.orig	2026-10-16 14:05:41 UTC
+++ host/cmake/Modules/UHDAtomics.cmake
@@ -104,9 +104,9 @@ macro(CHECK_ATOMICS_LIB_REQUIRED required_var)
                     message(FATAL_ERROR "Host compiler must support std::atomic!")
                 endif()
             else()
-                message(
-                    FATAL_ERROR
-                    "Boost appears to require libatomic, but cannot find it.")
+                # message(
+                #     FATAL_ERROR
+                #     "Boost appears to require libatomic, but cannot find it.")
             endif()
         endif()
     endif()
