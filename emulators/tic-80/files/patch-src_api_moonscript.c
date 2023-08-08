--- src/api/moonscript.c.orig	2023-05-22 10:36:00 UTC
+++ src/api/moonscript.c
@@ -86,9 +86,6 @@ static bool initMoonscript(tic_mem* tic, const char* c
     lua_State* lua = core->currentVM = luaL_newstate();
     lua_open_builtins(lua);
 
-    luaopen_lpeg(lua);
-    setloaded(lua, "lpeg");
-
     initLuaAPI(core);
 
     {
