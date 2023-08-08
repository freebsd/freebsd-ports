--- vendor/moonscript/moonscript.c.orig	2020-10-28 13:03:23 UTC
+++ vendor/moonscript/moonscript.c
@@ -27,9 +27,6 @@ void setloaded(lua_State* l, char* name) {
 extern int luaopen_lpeg(lua_State *l);
 
 LUALIB_API int luaopen_moonscript(lua_State *l) {
-	luaopen_lpeg(l);
-	setloaded(l, "lpeg");
-
 	if (luaL_loadbuffer(l, (const char *)moonscript_lua, moonscript_lua_len, "moonscript.lua") == 0) {
 		lua_call(l, 0, 1);
 		return 1;
