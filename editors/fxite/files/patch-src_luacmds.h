--- src/luacmds.h.orig	2013-10-03 09:22:51 UTC
+++ src/luacmds.h
@@ -17,5 +17,5 @@
 */
 
 
-const luaL_reg* LuaCommands(FXMainWindow*topwin);
+const luaL_Reg* LuaCommands(FXMainWindow*topwin);
 
