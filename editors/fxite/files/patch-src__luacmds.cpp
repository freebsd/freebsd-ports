--- src/luacmds.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/luacmds.cpp
@@ -530,7 +530,7 @@ static int view_clear_output(lua_State* 
 }
 
 
-static const struct luaL_reg fxte_commands[] = {
+static const struct luaL_Reg fxte_commands[] = {
   {"file_new",                  file_new},
   {"file_open",                 file_open},
   {"file_reload",               file_reload},
@@ -585,7 +585,7 @@ static const struct luaL_reg fxte_comman
 
 
 
-const luaL_reg* LuaCommands(FXMainWindow*topwin)
+const luaL_Reg* LuaCommands(FXMainWindow*topwin)
 {
   if (!tw) {
     tw=(TopWindow*)topwin;
