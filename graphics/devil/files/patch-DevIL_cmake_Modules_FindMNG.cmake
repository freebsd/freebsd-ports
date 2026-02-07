--- DevIL/cmake/Modules/FindMNG.cmake.orig	2017-01-01 23:37:37 UTC
+++ DevIL/cmake/Modules/FindMNG.cmake
@@ -1,6 +1,6 @@
 # Denton: Modified from the libsquish one
-FIND_PATH(MNG_INCLUDE_DIR mng.h PATHS . mng .. ../mng DOC "Directory containing libmng headers")
-FIND_LIBRARY(MNG_LIBRARY NAMES mng libmng PATHS . mng .. ../mng PATH_SUFFIXES lib lib64 release minsizerel relwithdebinfo DOC "Path to libmng library")
+FIND_PATH(MNG_INCLUDE_DIR libmng.h)
+FIND_LIBRARY(MNG_LIBRARY NAMES mng)
 
 SET(MNG_LIBRARIES ${MNG_LIBRARY})
 
