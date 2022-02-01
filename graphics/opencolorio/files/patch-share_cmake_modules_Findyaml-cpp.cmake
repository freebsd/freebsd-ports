--- share/cmake/modules/Findyaml-cpp.cmake.orig	2021-12-02 22:09:04 UTC
+++ share/cmake/modules/Findyaml-cpp.cmake
@@ -32,8 +32,8 @@ if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUAL ALL)
         # Search for yaml-cpp-config.cmake
         find_package(yaml-cpp ${yaml-cpp_FIND_VERSION} CONFIG QUIET)
     endif()
-
-    if(yaml-cpp_FOUND)
+    # while yaml-cpp.cmake finds yaml-cpp the LIBRARY fails to be set for 0.7.0??
+    if(NOT yaml-cpp_FOUND)
         get_target_property(yaml-cpp_LIBRARY yaml-cpp LOCATION)
     else()
 
