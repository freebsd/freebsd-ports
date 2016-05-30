--- CMake/FindLua.cmake.orig	2016-05-29 23:31:27 UTC
+++ CMake/FindLua.cmake
@@ -26,8 +26,8 @@ IF (WITH_LUAJIT)
     SET (LUA_INCLUDE_DIRS include/luajit-2.0 include)
 ELSE (WITH_LUAJIT)
     SET (LUA_INTERPRETER_TYPE "Lua")
-    SET (LUA_LIBRARY_NAME lua53 lua5.2 lua52 lua5.1 lua51 lua lua-5.1 liblua liblua.5.3.dylib)
-    SET (LUA_INCLUDE_DIRS include include/lua include/lua5.1 include/lua51 include/lua-5.1 include/lua5.2 include/lua5.3 include/lua-5.3)
+    SET (LUA_LIBRARY_NAME lua-5.1 lua-5.2 lua-5.3)
+    SET (LUA_INCLUDE_DIRS include include/lua include/lua51 include/lua52 include/lua53)
 ENDIF(WITH_LUAJIT)
 
 FIND_PATH (LUA_INCLUDE_DIR lua.h
