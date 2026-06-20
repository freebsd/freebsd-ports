--- src/host/premake.h.orig	2026-06-16 23:27:01 UTC
+++ src/host/premake.h
@@ -9,6 +9,11 @@
 #include "lauxlib.h"
 #include "lualib.h"
 
+#if LUA_VERSION_NUM >= 502
+#define luaL_register(L, n, f) \
+	do { if ((n) == NULL) luaL_setfuncs(L, f, 0); \
+		 else { luaL_newlib(L, f); lua_setglobal(L, n); } } while(0)
+#endif
 
 /* Identify the current platform I'm not sure how to reliably detect
  * Windows but since it is the most common I use it as the default */
@@ -88,4 +93,3 @@ int premake_execute(lua_State* L, int argc, const char
 int premake_init(lua_State* L);
 int premake_locate(lua_State* L, const char* argv0);
 int premake_execute(lua_State* L, int argc, const char** argv);
-
