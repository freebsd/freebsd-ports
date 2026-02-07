--- host/cmake/Modules/UHDAtomics.cmake.orig	2022-05-30 13:45:17 UTC
+++ host/cmake/Modules/UHDAtomics.cmake
@@ -102,9 +102,9 @@ macro(CHECK_ATOMICS_LIB_REQUIRED required_var)
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
