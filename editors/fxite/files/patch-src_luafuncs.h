--- src/luafuncs.h.orig	2013-10-03 09:22:51 UTC
+++ src/luafuncs.h
@@ -17,10 +17,10 @@
 */
 
 
-struct luaL_reg;
+struct luaL_Reg;
 class TopWindow;
 
-const luaL_reg* LuaFuncs();
+const luaL_Reg* LuaFuncs();
 void LuaFuncsCleanup();
 const char *LuaQuitMessage();
 
