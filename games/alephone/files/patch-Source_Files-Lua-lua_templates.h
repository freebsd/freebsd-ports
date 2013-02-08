--- Source_Files/Lua/lua_templates.h.orig	2012-04-21 17:57:45.000000000 +0400
+++ Source_Files/Lua/lua_templates.h	2012-04-21 17:58:22.000000000 +0400
@@ -496,7 +496,7 @@
 	static index_t ToIndex(lua_State *L, int index) {
 		index_t to;
 		if(lua_isnil(L, index)) return -1;
-		else if(_lookup(L, index, to)) return to;
+		else if(L_Enum<name, index_t>::_lookup(L, index, to)) return to;
 		else {
 			std::string error;
 			if(lua_isnumber(L, index) || lua_isstring(L, index))
