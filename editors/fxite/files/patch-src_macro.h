--- src/macro.h.orig	2013-10-03 09:22:51 UTC
+++ src/macro.h
@@ -25,7 +25,7 @@ struct lua_State;
 
 class MacroRunner: public FXObject {
 private:
-  FXDict keepers; // <- Data stored between Lua states
+  Dictionary keepers; // <- Data stored between Lua states
   void ClearKeepers();
   void PushKeepers(lua_State *L);
   void PopKeepers(lua_State *L);
