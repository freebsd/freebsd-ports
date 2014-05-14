--- cmake/FindLua51.cmake.orig	2014-03-11 21:24:37.000000000 +0100
+++ cmake/FindLua51.cmake	2014-03-11 21:23:43.000000000 +0100
@@ -4,7 +4,7 @@
 include(FindPackageHandleStandardArgs)
 
 find_path(LUA_H_PATH NAMES lua.h PATH_SUFFIXES lua5.1 lua51 lua)
-find_library(LUA_LIB NAMES lua5.1 lua51 lua PATH_SUFFIXES dynamic)
+find_library(LUA_LIB NAMES lua-5.1 lua51 lua PATH_SUFFIXES dynamic)
 find_library(LUA_LIB_DBG NAMES lua5.1_d lua51_d lua_d PATH_SUFFIXES dynamic)
 mark_as_advanced(LUA_H_PATH LUA_LIB LUA_LIB_DBG)
 
