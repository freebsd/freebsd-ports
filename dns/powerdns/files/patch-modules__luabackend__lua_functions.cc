--- modules/luabackend/lua_functions.cc.orig	2014-09-23 06:27:34 UTC
+++ modules/luabackend/lua_functions.cc
@@ -238,6 +238,7 @@
   return ret;
 }
 
+#ifndef __i386__
 bool LUABackend::getValueFromTable(lua_State *lua, const std::string& key, time_t& value) {
   lua_pushstring(lua, key.c_str()); 
   lua_gettable(lua, -2);  
@@ -253,6 +254,7 @@
   
   return ret;
 }
+#endif
 
 bool LUABackend::getValueFromTable(lua_State *lua, const std::string& key, uint32_t& value) {
   lua_pushstring(lua, key.c_str()); 
