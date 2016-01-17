--- cmake/FindLua.cmake.orig	2016-01-10 08:17:50 UTC
+++ cmake/FindLua.cmake
@@ -35,5 +35,5 @@ endif()
 
 find_package(PkgConfig)
 if(PKG_CONFIG_FOUND)
-  pkg_search_module(LUA lua5.3 lua-5.3 lua53 lua5.2 lua-5.2 lua52 lua5.1 lua-5.1 lua51 lua-5.0 lua5.0 lua50 lua)
+  pkg_search_module(LUA lua-${BSD_LUA_VER})
 endif()
