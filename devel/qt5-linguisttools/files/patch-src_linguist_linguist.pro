As we moved the libraries of Qt5 from /usr/local/lib to  /usr/local/lib/qt5 the
cmake files would get installed into /usr/local/lib/qt5/cmake. This howeever is
not really convenient for use with other applications depending on Qt via cmake.

For ports we could modify cmake.mk to always append /usr/local/lib/qt5 to the
search path. This would however still break applications outside of the ports
tree that users want to compile via cmake. An other option would be to patch
devel/cmake to add /usr/local/lib/qt5/cmake to the default search paths.

We chose the third option. To patch qmake's internal cmake generation function
to fix up the paths so that cmake files still land in the the "correct" location
in /usr/local/lib/cmake -- as this seemed to be the least intrusive method.

--- src/linguist/linguist.pro.orig	2016-06-03 17:47:52 UTC
+++ src/linguist/linguist.pro
@@ -17,7 +17,7 @@ CMAKE_INSTALL_LIBS_DIR = $$cmakeTargetPa
 contains(CMAKE_INSTALL_LIBS_DIR, ^(/usr)?/lib(64)?.*): CMAKE_USR_MOVE_WORKAROUND = $$CMAKE_INSTALL_LIBS_DIR
 
 CMAKE_LIB_DIR = $$cmakeRelativePath($$[QT_INSTALL_LIBS], $$[QT_INSTALL_PREFIX])
-!contains(CMAKE_LIB_DIR,"^\\.\\./.*") {
+!contains(CMAKE_LIB_DIR,"^\\.\\./.*")|freebsd {
     CMAKE_RELATIVE_INSTALL_LIBS_DIR = $$cmakeRelativePath($$[QT_INSTALL_PREFIX], $$[QT_INSTALL_LIBS])
     # We need to go up another two levels because the CMake files are
     # installed in $${CMAKE_LIB_DIR}/cmake/Qt5$${CMAKE_MODULE_NAME}
@@ -27,7 +27,7 @@ CMAKE_LIB_DIR = $$cmakeRelativePath($$[Q
 }
 
 CMAKE_BIN_DIR = $$cmakeRelativePath($$[QT_HOST_BINS], $$[QT_INSTALL_PREFIX])
-contains(CMAKE_BIN_DIR, "^\\.\\./.*") {
+contains(CMAKE_BIN_DIR, "^\\.\\./.*")|freebsd {
     CMAKE_BIN_DIR = $$[QT_HOST_BINS]/
     CMAKE_BIN_DIR_IS_ABSOLUTE = True
 }
@@ -45,6 +45,6 @@ cmake_linguist_macros_file.CONFIG = verb
 QMAKE_SUBSTITUTES += cmake_linguist_config_file cmake_linguist_config_version_file cmake_linguist_macros_file
 
 cmake_linguist_tools_files.files += $$cmake_linguist_config_file.output $$cmake_linguist_config_version_file.output $$cmake_linguist_macros_file.output
-cmake_linguist_tools_files.path = $$[QT_INSTALL_LIBS]/cmake/Qt5LinguistTools
+cmake_linguist_tools_files.path = $$[QT_INSTALL_PREFIX]/lib/cmake/Qt5LinguistTools
 cmake_linguist_tools_files.CONFIG = no_check_exists
 INSTALLS += cmake_linguist_tools_files
