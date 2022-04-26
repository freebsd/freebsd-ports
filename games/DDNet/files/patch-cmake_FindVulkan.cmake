--- cmake/FindVulkan.cmake.orig	2022-03-30 07:34:45 UTC
+++ cmake/FindVulkan.cmake
@@ -1,7 +1,7 @@
 if(NOT CMAKE_CROSSCOMPILING)
   find_package(PkgConfig QUIET)
   pkg_check_modules(PC_VULKAN vulkan)
-  if(PC_VULKAN_FOUND)
+  if(FALSE AND PC_VULKAN_FOUND)
     set(VULKAN_INCLUDE_DIRS "${PC_VULKAN_INCLUDE_DIRS}")
     set(VULKAN_LIBRARIES "${PC_VULKAN_LIBRARIES}")
     set(VULKAN_FOUND TRUE)
