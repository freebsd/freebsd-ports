-- Bump cmake_minimum_required to 3.5 for CMake 4.0 compatibility.
-- CMake 4.0 removed support for cmake_minimum_required(VERSION < 3.5).

--- CMake/Basis/ProjectTools.cmake.orig	2026-08-27 09:05:25 UTC
+++ CMake/Basis/ProjectTools.cmake
@@ -1879,7 +1879,7 @@
 macro (basis_project_initialize)
   # --------------------------------------------------------------------------
   # CMake version and policies
-  cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)
+  cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

   # Add policies introduced with CMake versions newer than the one specified
   # above. These policies would otherwise trigger a policy not set warning by
