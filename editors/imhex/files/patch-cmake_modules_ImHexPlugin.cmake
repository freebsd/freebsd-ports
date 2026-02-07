--- cmake/modules/ImHexPlugin.cmake.orig	2025-12-20 15:03:34 UTC
+++ cmake/modules/ImHexPlugin.cmake
@@ -29,10 +29,6 @@ macro(add_imhex_plugin)
         endif()
     endif()
 
-    if (IMHEX_PLUGIN_LIBRARY_PLUGIN)
-        install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/" DESTINATION "${SDK_PATH}/lib/plugins/${IMHEX_PLUGIN_NAME}")
-    endif()
-
     # Define new project for plugin
     project(${IMHEX_PLUGIN_NAME})
 
