--- deps/lua/src/lua_cjson.c.orig	2019-12-08 07:56:31.419672000 -0500
+++ deps/lua/src/lua_cjson.c	2019-12-08 07:56:52.389362000 -0500
@@ -1299,7 +1299,7 @@
  *
  * luaL_setfuncs() is used to create a module table where the functions have
  * json_config_t as their first upvalue. Code borrowed from Lua 5.2 source. */
-static void luaL_setfuncs (lua_State *l, const luaL_Reg *reg, int nup)
+void luaL_setfuncs (lua_State *l, const luaL_Reg *reg, int nup)
 {
     int i;
 
