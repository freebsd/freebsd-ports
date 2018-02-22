Make it possible to find qmobipocket/mobipocket.h when it installed into a
subdirectory of include/.
--- QMobipocketConfig.cmake.orig	2016-03-10 23:46:05 UTC
+++ QMobipocketConfig.cmake
@@ -5,7 +5,7 @@ get_filename_component( _currentDir  ${_
 
 # find the full paths to the library and the includes:
 find_path(QMOBIPOCKET_INCLUDE_DIR qmobipocket/mobipocket.h
-          HINTS ${_currentDir}/include
+          HINTS ${_currentDir}/include PATH_SUFFIXES kde4
           NO_DEFAULT_PATH)
 
 find_library(QMOBIPOCKET_LIBRARY qmobipocket 
