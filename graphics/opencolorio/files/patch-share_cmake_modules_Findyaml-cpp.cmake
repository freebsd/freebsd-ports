--- share/cmake/modules/Findyaml-cpp.cmake.orig	2023-01-06 02:05:59 UTC
+++ share/cmake/modules/Findyaml-cpp.cmake
@@ -41,8 +41,8 @@ if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUAL ALL)
         # Search for yaml-cpp-config.cmake
         find_package(yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG QUIET)
     endif()
-
-    if(yaml-cpp_FOUND)
+    # while yaml-cpp.cmake finds yaml-cpp the LIBRARY fails to be set for 0.7.0??
+    if(NOT yaml-cpp_FOUND)
         get_target_property(yaml-cpp_LIBRARY yaml-cpp LOCATION)
     else()
 
