--- src/lua_sysctl.c.orig	2021-03-01 07:11:51 UTC
+++ src/lua_sysctl.c
@@ -517,7 +517,7 @@ luaA_sysctl_get(lua_State *L)
 				if (intlen > sizeof(lua_Unsigned))
 					lua_pushnumber(L, umv);
 				else
-					lua_pushunsigned(L, umv);
+					lua_pushinteger(L, (lua_Integer)(umv));
 			}
 			lua_settable(L, -3);
 			len -= intlen;
