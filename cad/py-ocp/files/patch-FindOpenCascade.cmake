--- FindOpenCascade.cmake.orig	2020-06-12 09:48:04 UTC
+++ FindOpenCascade.cmake
@@ -69,6 +69,6 @@ foreach( MOD ${OCCT_MODULES})
 
 endforeach()
 
-target_include_directories( OPENCASCADE INTERFACE ${OPENCASCADE_INCLUDE_DIR})
+target_include_directories( OPENCASCADE INTERFACE OCCT ${OPENCASCADE_INCLUDE_DIR})
 
-find_package_handle_standard_args( OPENCASCADE DEFAULT_MSG OPENCASCADE_LIBRARIES OPENCASCADE_INCLUDE_DIR )
\ No newline at end of file
+find_package_handle_standard_args( OPENCASCADE DEFAULT_MSG OPENCASCADE_LIBRARIES OPENCASCADE_INCLUDE_DIR )
