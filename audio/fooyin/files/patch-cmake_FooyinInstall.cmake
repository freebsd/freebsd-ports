--- cmake/FooyinInstall.cmake.orig	2024-08-29 19:43:57 UTC
+++ cmake/FooyinInstall.cmake
@@ -2,7 +2,7 @@ set(LICENSE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING"
 
 set(README_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
 set(LICENSE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
-
+#[[
 install(
     FILES ${LICENSE_FILE}
     DESTINATION ${DOC_INSTALL_DIR}
@@ -16,7 +16,7 @@ install(
     RENAME README
     COMPONENT fooyin
 )
-
+]]
 install(FILES "${CMAKE_BINARY_DIR}/dist/linux/org.fooyin.fooyin.desktop"
         DESTINATION ${XDG_APPS_INSTALL_DIR}
         COMPONENT fooyin
