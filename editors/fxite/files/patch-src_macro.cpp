--- src/macro.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/macro.cpp
@@ -47,7 +47,7 @@ MacroRunner::~MacroRunner()
 /* Catch and report script errors */
 static FXint traceback(lua_State *L)
 {
-  lua_getfield(L, LUA_GLOBALSINDEX, "debug");
+  lua_getglobal(L, "debug");
   if (!lua_istable(L, -1)) {
     lua_pop(L, 1);
     return 1;
@@ -324,7 +324,7 @@ static void debug_hook(lua_State *L, lua_Debug *ar)
 /* Override a builtin Lua function, or add a new one if it doesn't exist */
 static void override(lua_State *L, const char*module, const char* funcname, lua_CFunction newfunc)
 {
-  lua_getfield(L,LUA_GLOBALSINDEX,module);
+  lua_getglobal(L,module);
   if (lua_istable(L,-1)) {
     lua_pushstring(L,funcname);
     if (newfunc) {
@@ -342,7 +342,7 @@ static void override(lua_State *L, const char*module, 
 /* Don't let scripts try to read from stdin, as this would block indefinitely */
 static void close_stdin(lua_State *L)
 {
-  lua_getfield(L, LUA_GLOBALSINDEX, "io");
+  lua_getglobal(L, "io");
   if (!lua_istable(L, -1)) {
     lua_pop(L, 1);
     return;
@@ -384,7 +384,7 @@ typedef struct {
 
 void MacroRunner::ClearKeepers()
 {
-  for (FXint i=keepers.first(); i<=keepers.last(); i=keepers.next(i)) {
+  if (UsedSlotsInDict(&keepers)>0) for (FXint i=0; i<TotalSlotsInDict(&keepers); ++i) {
     PersistRecord*pr=(PersistRecord*)keepers.data(i);
     if (pr) {
       if (pr->t==LUA_TSTRING) {
@@ -406,11 +406,12 @@ void MacroRunner::PushKeepers(lua_State *L)
     lua_pushstring(L,PERSIST_TABLE_NAME);
     lua_newtable(L);
     lua_settable(L, -3);
-    for (FXint i=keepers.first(); i<=keepers.last(); i=keepers.next(i)) {
+    if (UsedSlotsInDict(&keepers)>0) for (FXint i=0; i<TotalSlotsInDict(&keepers); ++i) {
       PersistRecord*pr=(PersistRecord*)keepers.data(i);
+      if (!pr) { continue; }
       lua_getglobal(L, LUA_MODULE_NAME);
       lua_getfield(L,-1,PERSIST_TABLE_NAME);
-      lua_pushstring(L,keepers.key(i));
+      lua_pushstring(L,DictKeyName(keepers,i));
       switch (pr->t) {
         case LUA_TNUMBER: { lua_pushnumber(L, pr->n);  break;}
         case LUA_TBOOLEAN:{ lua_pushboolean(L, pr->b); break;}
@@ -455,7 +456,7 @@ void MacroRunner::PopKeepers(lua_State *L)
             }
           }
           if (pr) {
-            keepers.replace(lua_tostring(L,-2), pr);
+            ReplaceInDict(&keepers,lua_tostring(L,-2),pr);
           }
         }
         lua_pop(L, 1);
@@ -479,6 +480,9 @@ bool MacroRunner::RunMacro(const FXString &source, boo
   lua_State *L=luaL_newstate();
   luaL_openlibs(L);
   luaopen_dialog(L);
+#if LUA_VERSION_NUM>=502
+  lua_setglobal(L, "dialog");
+#endif
   override(L,"os","exit", osexit);
   override(L,"io","stdin", NULL);
   override(L,"_G","print", print);
@@ -487,11 +491,27 @@ bool MacroRunner::RunMacro(const FXString &source, boo
   si->script=isfilename?source.text():NULL;
   states.append(si);
   lua_sethook(L,debug_hook,LUA_MASKLINE,1);
-  luaL_register(L, LUA_MODULE_NAME, LuaFuncs());
-  luaL_register(L, LUA_MODULE_NAME, LuaFxUtils(TopWinPub::instance(), EXE_NAME));
+#if LUA_VERSION_NUM<502
+  luaL_Register(L, LUA_MODULE_NAME, LuaFuncs());
+  luaL_Register(L, LUA_MODULE_NAME, LuaFxUtils(TopWinPub::instance(), EXE_NAME));
+  luaL_Register(L, LUA_MODULE_NAME, LuaCommands(TopWinPub::instance()));
+#else
+  int n=0;
+  const luaL_Reg*p;
+  const luaL_Reg*funcs = LuaFuncs();
+  const luaL_Reg*utils = LuaFxUtils(TopWinPub::instance(), EXE_NAME);
+  const luaL_Reg*cmds = LuaCommands(TopWinPub::instance());
+  for (p=funcs; p->name; p++) { n++; }
+  for (p=utils; p->name; p++) { n++; }
+  for (p=cmds; p->name; p++) { n++; }
+  lua_createtable(L, 0, n);
+  luaL_setfuncs(L, funcs, 0);
+  luaL_setfuncs(L, utils, 0);
+  luaL_setfuncs(L, cmds, 0);
+  lua_setglobal(L, LUA_MODULE_NAME);
+#endif
   override(L,LUA_MODULE_NAME,"script", scriptname);
   override(L,LUA_MODULE_NAME,"optimize", optimize);
-  luaL_openlib(L, LUA_MODULE_NAME, LuaCommands(TopWinPub::instance()), 0);
   set_string_token(L, "_VERSION", VERSION);
   PushKeepers(L);
   if (isfilename) {
