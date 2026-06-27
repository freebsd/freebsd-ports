--- src/host/premake.c.orig	2026-06-26 12:09:24 UTC
+++ src/host/premake.c
@@ -77,10 +77,24 @@ int premake_init(lua_State* L)
  */
 int premake_init(lua_State* L)
 {
+#if LUA_VERSION_NUM >= 502
+	luaL_newlib(L, path_functions);
+	lua_setglobal(L, "path");
+
+	luaL_requiref(L, "os", luaopen_os, 1);
+	lua_pop(L, 1);
+	lua_getglobal(L, "os");
+	luaL_setfuncs(L, os_functions, 0);
+	lua_pop(L, 1);
+
+	lua_getglobal(L, "string");
+	luaL_setfuncs(L, string_functions, 0);
+	lua_pop(L, 1);
+#else
 	luaL_register(L, "path",   path_functions);
 	luaL_register(L, "os",     os_functions);
 	luaL_register(L, "string", string_functions);
-
+#endif
 	/* push the application metadata */
 	lua_pushstring(L, LUA_COPYRIGHT);
 	lua_setglobal(L, "_COPYRIGHT");
