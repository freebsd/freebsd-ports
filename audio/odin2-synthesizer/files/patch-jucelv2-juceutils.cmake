-- Add BSD support to JUCELV2 CMake utilities.

--- libs/JUCELV2/extras/Build/CMake/JUCEUtils.cmake.orig	2026-05-17 03:55:19 UTC
+++ libs/JUCELV2/extras/Build/CMake/JUCEUtils.cmake
@@ -84,7 +84,7 @@ set_property(GLOBAL PROPERTY JUCE_COPY_PLUGIN_AFTER_BU
     FULL_DOCS "Whether or not plugins should be copied after building")
 set_property(GLOBAL PROPERTY JUCE_COPY_PLUGIN_AFTER_BUILD FALSE)
 
-if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
+if(((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD")) OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
     _juce_create_pkgconfig_target(JUCE_CURL_LINUX_DEPS libcurl)
     _juce_create_pkgconfig_target(JUCE_BROWSER_LINUX_DEPS webkit2gtk-4.0 gtk+-x11-3.0)
 elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
@@ -116,7 +116,7 @@ function(_juce_set_default_properties)
 
         set_property(GLOBAL PROPERTY JUCE_VST3_COPY_DIR "${prefix}/VST3")
         set_property(GLOBAL PROPERTY JUCE_AAX_COPY_DIR  "${prefix}/Avid/Audio/Plug-Ins")
-    elseif((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
+    elseif(((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD")) OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
         set_property(GLOBAL PROPERTY JUCE_VST_COPY_DIR  "$ENV{HOME}/.vst")
         set_property(GLOBAL PROPERTY JUCE_VST3_COPY_DIR "$ENV{HOME}/.vst3")
         set_property(GLOBAL PROPERTY JUCE_LV2_COPY_DIR "$ENV{HOME}/.lv2")
@@ -218,7 +218,7 @@ function(_juce_link_optional_libraries target)
 # know they need it. Otherwise, we won't link anything.
 # See the NEEDS_CURL, NEEDS_WEB_BROWSER, and NEEDS_STORE_KIT options in the CMake/readme.md.
 function(_juce_link_optional_libraries target)
-    if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
+    if(((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD")) OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
         get_target_property(needs_curl ${target} JUCE_NEEDS_CURL)
 
         if(needs_curl)
@@ -898,7 +898,7 @@ function(_juce_set_plugin_target_properties shared_cod
 
         set(output_path "${products_folder}/${product_name}.vst3")
 
-        if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
+        if(((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD")) OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
             set_target_properties(${target_name} PROPERTIES
                 SUFFIX .so
                 LIBRARY_OUTPUT_DIRECTORY "${output_path}/Contents/${JUCE_TARGET_ARCHITECTURE}-linux")
@@ -934,7 +934,7 @@ function(_juce_set_plugin_target_properties shared_cod
 
         set(output_path "${products_folder}/${product_name}.lv2")
 
-        if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
+        if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
             # On linux we assume that the output arch is the same as the that of the host platform
             set(is_platform_x64 $<EQUAL:${CMAKE_SIZEOF_VOID_P},8>)
             set(arch_string $<IF:${is_platform_x64},x86_64,i386>)
@@ -1082,7 +1082,7 @@ function(_juce_link_plugin_wrapper shared_code_target 
         add_library(${target_name} MODULE)
     endif()
 
-    if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
+    if(((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD")) OR (CMAKE_SYSTEM_NAME MATCHES ".*BSD"))
         target_link_options(${target_name} PRIVATE "-Wl,--no-undefined")
     endif()
 
