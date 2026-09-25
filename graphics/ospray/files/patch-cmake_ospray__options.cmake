-- Allow newer rkcommon versions (e.g. 1.15.x installed in ports vs 1.14.0 required)
-- Remove EXACT so any rkcommon >= 1.14.0 with same major version is accepted.
--- cmake/ospray_options.cmake.orig	2026-09-25 03:41:52 UTC
+++ cmake/ospray_options.cmake
@@ -76,7 +76,7 @@ option(OSPRAY_ENABLE_VOLUMES "Enable volume rendering 
 ###########################################################
 
 # rkcommon
-find_package(rkcommon ${RKCOMMON_VERSION_REQUIRED} EXACT REQUIRED)
+find_package(rkcommon ${RKCOMMON_VERSION_REQUIRED} REQUIRED)
 get_target_property(RKCOMMON_INCLUDE_DIRS rkcommon::rkcommon
   INTERFACE_INCLUDE_DIRECTORIES)
 
