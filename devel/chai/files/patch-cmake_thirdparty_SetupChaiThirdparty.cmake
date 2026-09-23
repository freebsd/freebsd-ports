-- Find the externally installed umpire and raja packages in the standard
-- FreeBSD prefix, because CHAI otherwise only searches in user-supplied
-- paths or falls back to bundled submodules.

--- cmake/thirdparty/SetupChaiThirdparty.cmake.orig	2026-09-23 06:32:45 UTC
+++ cmake/thirdparty/SetupChaiThirdparty.cmake
@@ -5,6 +5,8 @@
 # SPDX-License-Identifier: BSD-3-Clause
 ##############################################################################

+find_package(umpire CONFIG REQUIRED)
+
 if (NOT TARGET umpire::umpire AND NOT TARGET umpire)
   if (DEFINED umpire_DIR OR DEFINED UMPIRE_DIR)
     message(STATUS "[CHAI] Using external Umpire")
@@ -37,6 +39,8 @@ if (CHAI_ENABLE_RAJA_PLUGIN)
 endif ()
 
 if (CHAI_ENABLE_RAJA_PLUGIN)
+  find_package(raja CONFIG REQUIRED)
+
   if (NOT TARGET RAJA)
     if (DEFINED raja_DIR OR DEFINED RAJA_DIR)
       message(STATUS "[CHAI] Using external RAJA")
