diff --git a/Modules/FindLua.cmake b/Modules/FindLua.cmake
index 8f35fc7f1..cdce60866 100644
--- Modules/FindLua.cmake
+++ Modules/FindLua.cmake
@@ -35,6 +35,8 @@
 #
 # This is because, the lua location is not standardized and may exist in
 # locations other than lua/
+cmake_policy(PUSH)
+cmake_policy(SET CMP0012 NEW)
 
 unset(_lua_include_subdirs)
 unset(_lua_library_names)
@@ -236,3 +238,4 @@ FIND_PACKAGE_HANDLE_STANDARD_ARGS(Lua
                                   VERSION_VAR LUA_VERSION_STRING)
 
 mark_as_advanced(LUA_INCLUDE_DIR LUA_LIBRARY LUA_MATH_LIBRARY)
+cmake_policy(POP)
