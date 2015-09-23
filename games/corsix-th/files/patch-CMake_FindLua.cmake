--- CMake/FindLua.cmake.orig	2015-08-30 20:29:45 UTC
+++ CMake/FindLua.cmake
@@ -26,8 +26,8 @@ IF (WITH_LUAJIT)
     SET (LUA_INCLUDE_DIRS include/luajit-2.0 include)
 ELSE (WITH_LUAJIT)
     SET (LUA_INTERPRETER_TYPE "Lua")
-    SET (LUA_LIBRARY_NAME lua53 lua52 lua5.1 lua51 lua lua-5.1 liblua)
-    SET (LUA_INCLUDE_DIRS include include/lua include/lua5.1 include/lua51 include/lua-5.1)
+    SET (LUA_LIBRARY_NAME lua-5.1 lua-5.2 lua-5.3)
+    SET (LUA_INCLUDE_DIRS include include/lua include/lua51 include/lua52 include/lua53)
 ENDIF(WITH_LUAJIT)
 
 FIND_PATH (LUA_INCLUDE_DIR lua.h
