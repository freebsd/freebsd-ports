--- src/lua_sysctl.c.orig	2016-12-23 20:58:56 UTC
+++ src/lua_sysctl.c
@@ -582,7 +582,7 @@ luaA_sysctl_IK2farenheit(lua_State *L)
  */
 
 
-static const luaL_reg lua_sysctl[] =
+static const luaL_Reg lua_sysctl[] =
 {
 	{"get",			luaA_sysctl_get},
 	{"set",			luaA_sysctl_set},
@@ -598,7 +598,11 @@ LUALIB_API int
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
 
