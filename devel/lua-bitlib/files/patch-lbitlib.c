--- ./lbitlib.c.orig	2007-11-16 14:14:40.000000000 +0100
+++ ./lbitlib.c	2014-01-10 18:19:01.197863901 +0100
@@ -42,7 +42,7 @@
 TDYADIC(rshift,  >>, UInteger, UInteger)
 TDYADIC(arshift, >>, Integer, UInteger)
 
-static const struct luaL_reg bitlib[] = {
+static const struct luaL_Reg bitlib[] = {
   {"cast",    bit_cast},
   {"bnot",    bit_bnot},
   {"band",    bit_band},
@@ -55,6 +55,9 @@
 };
 
 LUALIB_API int luaopen_bit (lua_State *L) {
-  luaL_openlib(L, "bit", bitlib, 0);
+  lua_newtable(L);
+  luaL_setfuncs(L, bitlib, 0);
+  lua_pushvalue(L,-1);
+  lua_setglobal(L,"bit");
   return 1;
 }
