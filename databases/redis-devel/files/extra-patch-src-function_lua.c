--- src/function_lua.c.orig	2022-01-31 19:49:57.000000000 +0900
+++ src/function_lua.c	2022-02-01 05:03:43.442197000 +0900
@@ -52,6 +52,10 @@
 #define LIBRARY_API_NAME "__LIBRARY_API__"
 #define LOAD_TIMEOUT_MS 500
 
+#ifndef lua_unref
+#define lua_unref(L,ref)        luaL_unref(L, LUA_REGISTRYINDEX, (ref))
+#endif
+
 /* Lua engine ctx */
 typedef struct luaEngineCtx {
     lua_State *lua;
