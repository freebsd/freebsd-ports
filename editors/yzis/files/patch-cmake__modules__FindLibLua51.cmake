--- ./cmake/modules/FindLibLua51.cmake.orig	2008-06-25 22:35:28.000000000 +0000
+++ ./cmake/modules/FindLibLua51.cmake	2014-06-01 20:37:47.000000000 +0000
@@ -28,6 +28,7 @@
 FIND_PACKAGE(GNUWIN32)
 
 FIND_PATH(LIBLUA51_INCLUDE_DIR lua.h
+   ${LUA_INCDIR}
    ${WITH_LUA_HOME}/include
    ${_libLua51IncDir}/lua51
    ${_libLua51IncDir}/lua5.1
@@ -39,8 +40,9 @@
    ${GNUWIN32_DIR}/include
 )
 
-FIND_LIBRARY(LIBLUA51_LIBRARIES NAMES lua5.1 lua51 lua
+FIND_LIBRARY(LIBLUA51_LIBRARIES NAMES lua-5.1 lua5.1 lua51 lua
    PATHS
+   ${LUA_LIBDIR}
    ${WITH_LUA_HOME}/lib
    ${_libLua51LinkDir}
    ${_libLuaLinkDir}
