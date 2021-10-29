--- FindOpenCascade.cmake.orig	2021-04-19 17:00:03 UTC
+++ FindOpenCascade.cmake
@@ -76,4 +76,4 @@ endforeach()
 
 target_include_directories( OPENCASCADE INTERFACE ${OPENCASCADE_INCLUDE_DIR})
 
-find_package_handle_standard_args( OPENCASCADE DEFAULT_MSG OPENCASCADE_LIBRARIES OPENCASCADE_INCLUDE_DIR )
+find_package_handle_standard_args( OpenCascade DEFAULT_MSG OPENCASCADE_LIBRARIES OPENCASCADE_INCLUDE_DIR )
