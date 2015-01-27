--- cmake/FindLua.cmake.orig	2015-01-12 09:12:09.922611844 +0000
+++ cmake/FindLua.cmake	2015-01-12 09:23:01.083607077 +0000
@@ -35,5 +35,5 @@
 
 find_package(PkgConfig)
 if(PKG_CONFIG_FOUND)
-  pkg_search_module(LUA lua5.2 lua-5.2 lua52 lua5.1 lua-5.1 lua51 lua-5.0 lua5.0 lua50 lua)
+  pkg_search_module(LUA lua-${BSD_LUA_VER})
 endif()
