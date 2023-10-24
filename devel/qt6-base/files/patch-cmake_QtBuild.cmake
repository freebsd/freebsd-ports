--- cmake/QtBuild.cmake.orig	2023-09-21 19:24:26 UTC
+++ cmake/QtBuild.cmake
@@ -203,7 +203,7 @@ function(qt_internal_set_up_global_paths)
     if(QT_CONFIG_INSTALL_DIR)
         string(APPEND QT_CONFIG_INSTALL_DIR "/")
     endif()
-    string(APPEND QT_CONFIG_INSTALL_DIR ${__config_path_part})
+    string(APPEND QT_CONFIG_INSTALL_DIR "lib/cmake")
 
     set(QT_BUILD_DIR "${QT_BUILD_DIR}" PARENT_SCOPE)
     set(QT_INSTALL_DIR "${QT_INSTALL_DIR}" PARENT_SCOPE)
