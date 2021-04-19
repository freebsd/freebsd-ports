Part of https://github.com/KhronosGroup/Vulkan-Loader/commit/eb6d6f95dff8

$ make check-plist
====> Checking for pkg-plist issues (check-plist)
===> Parsing plist
===> Checking for items in STAGEDIR missing from pkg-plist
Error: Orphaned: lib/libvulkan.so.0.0.176
===> Checking for items in pkg-plist which are not in STAGEDIR
Error: Missing: lib/libvulkan.so.1.2.176
===> Error: Plist issues found.
*** Error code 1

--- cmake/FindVulkanHeaders.cmake.orig	2021-03-29 20:05:47 UTC
+++ cmake/FindVulkanHeaders.cmake
@@ -114,19 +114,19 @@ endif()
 file(STRINGS
         ${VulkanHeaders_main_header}
         VulkanHeaders_lines
-        REGEX "^#define (VK_API_VERSION.*VK_MAKE_VERSION|VK_HEADER_VERSION)")
+        REGEX "^#define VK_HEADER_VERSION(_COMPLETE)? ")
 
 foreach(VulkanHeaders_line ${VulkanHeaders_lines})
 
     # First, handle the case where we have a major/minor version
     #   Format is:
-    #        #define VK_API_VERSION_X_Y VK_MAKE_VERSION(X, Y, 0)
+    #        #define VK_HEADER_VERSION_COMPLETE VK_MAKE_API_VERSION(0, X, Y, VK_HEADER_VERSION)
     #   We grab the major version (X) and minor version (Y) out of the parentheses
-    string(REGEX MATCH "VK_MAKE_VERSION\\(.*\\)" VulkanHeaders_out ${VulkanHeaders_line})
+    string(REGEX MATCH "VK_HEADER_VERSION_COMPLETE VK_MAKE_API_VERSION\\(.*\\)" VulkanHeaders_out ${VulkanHeaders_line})
     string(REGEX MATCHALL "[0-9]+" VulkanHeaders_MAJOR_MINOR "${VulkanHeaders_out}")
     if (VulkanHeaders_MAJOR_MINOR)
-        list (GET VulkanHeaders_MAJOR_MINOR 0 VulkanHeaders_cur_major)
-        list (GET VulkanHeaders_MAJOR_MINOR 1 VulkanHeaders_cur_minor)
+        list (GET VulkanHeaders_MAJOR_MINOR 1 VulkanHeaders_cur_major)
+        list (GET VulkanHeaders_MAJOR_MINOR 2 VulkanHeaders_cur_minor)
         if (${VulkanHeaders_cur_major} GREATER ${VulkanHeaders_VERSION_MAJOR})
             set(VulkanHeaders_VERSION_MAJOR ${VulkanHeaders_cur_major})
             set(VulkanHeaders_VERSION_MINOR ${VulkanHeaders_cur_minor})
