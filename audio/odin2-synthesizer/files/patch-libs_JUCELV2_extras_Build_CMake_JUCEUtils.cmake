--- libs/JUCELV2/extras/Build/CMake/JUCEUtils.cmake.orig	2025-02-22 09:54:25 UTC
+++ libs/JUCELV2/extras/Build/CMake/JUCEUtils.cmake
@@ -934,7 +934,7 @@ function(_juce_set_plugin_target_properties shared_cod
 
         set(output_path "${products_folder}/${product_name}.lv2")
 
-        if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
+        if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
             # On linux we assume that the output arch is the same as the that of the host platform
             set(is_platform_x64 $<EQUAL:${CMAKE_SIZEOF_VOID_P},8>)
             set(arch_string $<IF:${is_platform_x64},x86_64,i386>)
