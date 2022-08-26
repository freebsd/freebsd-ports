--- cmake/QtBuild.cmake.orig	2022-05-25 08:58:52 UTC
+++ cmake/QtBuild.cmake
@@ -198,7 +198,7 @@ function(qt_internal_set_up_global_paths)
     if(QT_CONFIG_INSTALL_DIR)
         string(APPEND QT_CONFIG_INSTALL_DIR "/")
     endif()
-    string(APPEND QT_CONFIG_INSTALL_DIR ${__config_path_part})
+    string(APPEND QT_CONFIG_INSTALL_DIR "lib/cmake")
 
     set(QT_BUILD_DIR "${QT_BUILD_DIR}" PARENT_SCOPE)
     set(QT_INSTALL_DIR "${QT_INSTALL_DIR}" PARENT_SCOPE)
