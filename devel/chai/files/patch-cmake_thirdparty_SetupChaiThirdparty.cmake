--- cmake/thirdparty/SetupChaiThirdparty.cmake.orig	2025-10-30 17:20:50 UTC
+++ cmake/thirdparty/SetupChaiThirdparty.cmake
@@ -5,6 +5,8 @@
 # SPDX-License-Identifier: BSD-3-Clause
 ##############################################################################
 
+find_package(umpire REQUIRED)
+
 if (NOT TARGET umpire)
   if (DEFINED umpire_DIR OR DEFINED UMPIRE_DIR)
     message(STATUS "[CHAI] Using external Umpire")
@@ -27,6 +29,8 @@ endif ()
     endif ()
   endif ()
 endif ()
+
+find_package(raja REQUIRED)
 
 if (CHAI_ENABLE_RAJA_PLUGIN)
   if (NOT TARGET RAJA)
