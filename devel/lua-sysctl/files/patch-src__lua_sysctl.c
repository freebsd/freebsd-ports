--- ./src/lua_sysctl.c.orig	2013-03-06 16:38:20.000000000 +0100
+++ ./src/lua_sysctl.c	2014-01-10 18:09:08.582550597 +0100
@@ -596,7 +596,7 @@
  */
 
 
-static const luaL_reg lua_sysctl[] =
+static const luaL_Reg lua_sysctl[] =
 {
 	{"get",			luaA_sysctl_get},
 	{"set",			luaA_sysctl_set},
@@ -612,7 +612,11 @@
 luaopen_sysctl_core(lua_State *L)
 {
 
-	luaL_openlib(L, "sysctl", lua_sysctl, 0);
+	lua_newtable(L);
+	luaL_setfuncs(L, lua_sysctl,0);
+	lua_pushvalue(L,-1);
+	lua_setglobal(L,"sysctl");
+
 	return (1);
 }
 
