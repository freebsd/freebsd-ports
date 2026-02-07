--- cmake/InstallAndPackage.cmake.orig	2021-04-01 12:33:44 UTC
+++ cmake/InstallAndPackage.cmake
@@ -33,7 +33,6 @@ install(DIRECTORY
         COMPONENT language_files)
 
 install(FILES
-                ${CMAKE_SOURCE_DIR}/COPYING.md
                 ${CMAKE_SOURCE_DIR}/README.md
                 ${CMAKE_SOURCE_DIR}/changelog.txt
                 ${CMAKE_SOURCE_DIR}/docs/multiplayer.md
@@ -58,7 +57,7 @@ if(OPTION_INSTALL_FHS)
             COMPONENT manual)
 endif()
 
-if(UNIX AND NOT APPLE AND NOT EMSCRIPTEN)
+if(UNIX AND NOT APPLE AND NOT EMSCRIPTEN AND NOT OPTION_DEDICATED)
     install(DIRECTORY
                     ${CMAKE_BINARY_DIR}/media/icons
                     ${CMAKE_BINARY_DIR}/media/pixmaps
