--- src/luafuncs.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/luafuncs.cpp
@@ -25,8 +25,8 @@
 #include <FX88591Codec.h>
 #include <FXUTF16Codec.h>
 
-#include "macro.h"
 #include "compat.h"
+#include "macro.h"
 #include "appwin_pub.h"
 #include "scidoc.h"
 #include "doctabs.h"
@@ -38,6 +38,9 @@
 #include "intl.h"
 #include "luafuncs.h"
 
+#if LUA_VERSION_NUM<502
+# define lua_rawlen lua_objlen
+#endif
 
 
 /*
@@ -86,7 +89,7 @@ static bool check_find_flags(lua_State* 
 {
   flags=0;
   luaL_argcheck(L, lua_istable(L,pos), pos, _("expected table"));
-  int n=lua_objlen(L, pos);
+  int n=lua_rawlen(L, pos);
   for (int i=1; i<=n; i++) {
     lua_rawgeti(L, pos, i);
     if (lua_isstring(L,-1)) {
@@ -287,7 +290,7 @@ static int select(lua_State* L)
     sel_start=luaL_checkinteger(L,1);
     sel_end=(1==argc)?sel_start:luaL_checkinteger(L,2);
     sci->sendMessage(SCI_SETSELECTIONMODE, rectsel?SC_SEL_RECTANGLE:SC_SEL_STREAM, 0);
-    sci->sendMessage(SCI_SETCURRENTPOS, sel_end, FALSE);
+    sci->sendMessage(SCI_SETCURRENTPOS, sel_end, false);
     sci->sendMessage(SCI_SETANCHOR, sel_start, 0);
     sci->ScrollCaret();
     sci->sendMessage(SCI_SETSELECTIONMODE, rectsel?SC_SEL_RECTANGLE:SC_SEL_STREAM, 0);
@@ -1354,7 +1357,7 @@ static int tagfiles(lua_State* L)
 
 
 
-static const struct luaL_reg fxte_funcs[] = {
+static const struct luaL_Reg fxte_funcs[] = {
   {"seltext", seltext},
   {"text", text},
   {"documents", documents},
@@ -1403,7 +1406,7 @@ static const struct luaL_reg fxte_funcs[
 
 
 
-const luaL_reg* LuaFuncs()
+const luaL_Reg* LuaFuncs()
 {
   return fxte_funcs;
 }
