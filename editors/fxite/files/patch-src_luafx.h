--- src/luafx.h.orig	2013-10-03 09:22:51 UTC
+++ src/luafx.h
@@ -17,5 +17,5 @@
 */
 
 
-const luaL_reg* LuaFxUtils(FXWindow*topwin, const char*exe_name);
+const luaL_Reg* LuaFxUtils(FXWindow*topwin, const char*exe_name);
 
