--- modules/luabackend/luabackend.hh.orig	2014-09-23 06:27:34 UTC
+++ modules/luabackend/luabackend.hh
@@ -155,7 +155,9 @@
 //  FUNCTIONS TO THIS BACKEND
     bool getValueFromTable(lua_State *lua, const std::string& key, string& value);
     bool getValueFromTable(lua_State *lua, uint32_t key, string& value);
+#ifndef __i386__
     bool getValueFromTable(lua_State *lua, const std::string& key, time_t& value);
+#endif
     bool getValueFromTable(lua_State *lua, const std::string& key, uint32_t& value);
     bool getValueFromTable(lua_State *lua, const std::string& key, uint16_t& value);
     bool getValueFromTable(lua_State *lua, const std::string& key, int& value);
