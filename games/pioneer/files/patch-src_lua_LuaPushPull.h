--- src/lua/LuaPushPull.h.orig	2023-02-03 08:11:26 UTC
+++ src/lua/LuaPushPull.h
@@ -5,6 +5,7 @@
 #define _LUAPUSHPULL_H
 
 #include "Lua.h"
+#include "buildopts.h"
 #include <lua.hpp>
 
 #include <cstddef>
@@ -15,7 +16,9 @@ inline void pi_lua_generic_push(lua_State *l, bool val
 inline void pi_lua_generic_push(lua_State *l, int value) { lua_pushinteger(l, value); }
 inline void pi_lua_generic_push(lua_State *l, int64_t value) { lua_pushinteger(l, value); }
 inline void pi_lua_generic_push(lua_State *l, unsigned int value) { lua_pushinteger(l, value); }
+#if SIZE_T_AND_UNSIGNED_INT_ARE_DIFFERENT_TYPES
 inline void pi_lua_generic_push(lua_State *l, size_t value) { lua_pushinteger(l, value); }
+#endif
 inline void pi_lua_generic_push(lua_State *l, double value) { lua_pushnumber(l, value); }
 inline void pi_lua_generic_push(lua_State *l, const char *value) { lua_pushstring(l, value); }
 inline void pi_lua_generic_push(lua_State *l, const std::string &value)
@@ -32,7 +35,9 @@ inline void pi_lua_generic_pull(lua_State *l, int inde
 inline void pi_lua_generic_pull(lua_State *l, int index, int &out) { out = luaL_checkinteger(l, index); }
 inline void pi_lua_generic_pull(lua_State *l, int index, int64_t &out) { out = luaL_checkinteger(l, index); }
 inline void pi_lua_generic_pull(lua_State *l, int index, unsigned int &out) { out = luaL_checkunsigned(l, index); }
+#if SIZE_T_AND_UNSIGNED_INT_ARE_DIFFERENT_TYPES
 inline void pi_lua_generic_pull(lua_State *l, int index, size_t &out) { out = luaL_checkunsigned(l, index); }
+#endif
 inline void pi_lua_generic_pull(lua_State *l, int index, float &out) { out = luaL_checknumber(l, index); }
 inline void pi_lua_generic_pull(lua_State *l, int index, double &out) { out = luaL_checknumber(l, index); }
 inline void pi_lua_generic_pull(lua_State *l, int index, const char *&out) { out = luaL_checkstring(l, index); }
