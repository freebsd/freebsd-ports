-- Bump cmake_minimum_required to 3.5 for CMake 4.0 compatibility.
-- CMake 4.0 removed support for cmake_minimum_required(VERSION < 3.5).

--- CMake/Basis/BasisSettings.cmake.orig	2026-08-27 09:05:25 UTC
+++ CMake/Basis/BasisSettings.cmake
@@ -46,7 +46,7 @@
 # CMake version and policies
 # ============================================================================

-cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)
+cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

 # Add policies introduced with CMake versions newer than the one specified
 # above. These policies would otherwise trigger a policy not set warning by
