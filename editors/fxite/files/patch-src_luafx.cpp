--- src/luafx.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/luafx.cpp
@@ -36,6 +36,10 @@
 #include "intl.h"
 #include "luafx.h"
 
+#if LUA_VERSION_NUM<502
+# define lua_rawlen lua_objlen
+#endif
+
 static FXWindow*main_window=NULL;
 
 static const char*default_title;
@@ -173,7 +177,7 @@ static int input(lua_State*L)
   switch (toupper(type[0])) {
     case 'I' : {
       if (!lua_isnil(L,3)) {
-        txt.format(sizeof(lua_Integer)>4?"%ld":"%d", luaL_checkinteger(L,3));
+        txt.format("%ld", luaL_checkinteger(L,3));
       }
       opt=INPUTDIALOG_INTEGER;
       break;
@@ -248,7 +252,7 @@ static int choose(lua_State*L) {
   FXString fmsg;
   int i,n;
   luaL_argcheck(L, lua_istable(L,argtbl), argtbl, _("table expected") );
-  n=lua_objlen(L,argtbl);
+  n=lua_rawlen(L,argtbl);
   luaL_argcheck(L, n>0, argtbl, _("table can't be empty"));
   for (i=1;i<=n; i++) {
     lua_rawgeti(L,argtbl,i);
@@ -599,7 +603,7 @@ static int pid(lua_State* L)
 
 
 
-static const struct luaL_reg fx_util_funcs[] = {
+static const struct luaL_Reg fx_util_funcs[] = {
   {"message", message},
   {"confirm", confirm},
   {"input", input},
@@ -620,7 +624,7 @@ static const struct luaL_reg fx_util_funcs[] = {
 
 
 
-const luaL_reg* LuaFxUtils(FXWindow*topwin, const char*exe_name)
+const luaL_Reg* LuaFxUtils(FXWindow*topwin, const char*exe_name)
 {
   default_title=exe_name;
   if (!main_window) { main_window=topwin; }
