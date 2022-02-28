--- cmake/FindMsgPuck.cmake.orig	2021-11-26 15:16:51 UTC
+++ cmake/FindMsgPuck.cmake
@@ -7,7 +7,7 @@
 #
 
 find_path(MSGPUCK_INCLUDE_DIR msgpuck.h PATH_SUFFIXES msgpuck)
-find_library(MSGPUCK_LIBRARY NAMES libmsgpuck.a)
+find_library(MSGPUCK_LIBRARY NAMES libmsgpuck.so)
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(MsgPuck
