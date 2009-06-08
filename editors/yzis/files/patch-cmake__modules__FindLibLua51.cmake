--- ./cmake/modules/FindLibLua51.cmake.orig	2008-06-26 01:35:28.000000000 +0300
+++ ./cmake/modules/FindLibLua51.cmake	2009-06-08 14:29:41.309522776 +0300
@@ -28,6 +28,7 @@
 FIND_PACKAGE(GNUWIN32)
 
 FIND_PATH(LIBLUA51_INCLUDE_DIR lua.h
+   ${LUA_INCDIR}
    ${WITH_LUA_HOME}/include
    ${_libLua51IncDir}/lua51
    ${_libLua51IncDir}/lua5.1
@@ -41,6 +42,7 @@
 
 FIND_LIBRARY(LIBLUA51_LIBRARIES NAMES lua5.1 lua51 lua
    PATHS
+   ${LUA_LIBDIR}
    ${WITH_LUA_HOME}/lib
    ${_libLua51LinkDir}
    ${_libLuaLinkDir}
