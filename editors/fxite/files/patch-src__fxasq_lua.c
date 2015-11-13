--- src/fxasq_lua.c.orig	2013-10-03 09:22:51 UTC
+++ src/fxasq_lua.c
@@ -31,6 +31,9 @@
 #include "intl.h"
 #include "fxasq_lua.h"
 
+#if LUA_VERSION_NUM<502
+# define lua_rawlen lua_objlen
+#endif
 
 #define DLG_MODULE_NAME "dialog"
 #define MetaName "_fxasq_metatable"
@@ -234,7 +237,7 @@ static int asq_new(lua_State *L) {
   if (argc>=2) {
     luaL_argcheck(L,lua_istable(L,2),2,_("expected table"));
   }
-  n=lua_objlen(L,2);
+  n=lua_rawlen(L,2);
   for (i=1;i<=n; i++) {
     lua_rawgeti(L,2,i);
     char msg[64];
@@ -301,7 +304,7 @@ static int asq_done(lua_State *L)
 
 
 
-static const struct luaL_reg asq_funcs[] = {
+static const struct luaL_Reg asq_funcs[] = {
   {"new",      asq_new},
   {"run",      asq_run},
   {"label",    asq_label},
@@ -330,12 +333,15 @@ int luaopen_dialog(lua_State *L)
   lua_pushvalue(L, -2);
   lua_settable(L, -3);
 
-  luaL_getmetatable(L, MetaName);
   lua_pushstring(L,"__gc");
   lua_pushcfunction(L,asq_done);
   lua_rawset(L,-3);
 
-  luaL_register(L, NULL, &asq_funcs[1]);
-  luaL_register(L, DLG_MODULE_NAME, asq_funcs);
-  return 0;
+#if LUA_VERSION_NUM < 502
+  luaL_Register(L, NULL, &asq_funcs[1]);
+  luaL_Register(L, DLG_MODULE_NAME, asq_funcs);
+#else
+  luaL_setfuncs(L,asq_funcs,0);
+#endif
+  return 1;
 }
