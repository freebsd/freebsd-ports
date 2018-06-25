--- src/stratagus/script.cpp.orig	2016-11-08 14:38:09 UTC
+++ src/stratagus/script.cpp
@@ -767,7 +767,7 @@ NumberDesc *CclParseNumberDesc(lua_State
 			lua_pop(l, 1); // table.
 		} else {
 			lua_pop(l, 1);
-			LuaError(l, "unknow condition '%s'"_C_ key);
+			LuaError(l, "unknow condition '%s'" _C_ key);
 		}
 	} else {
 		LuaError(l, "Parse Error in ParseNumber");
@@ -881,7 +881,7 @@ StringDesc *CclParseStringDesc(lua_State
 			res->D.PlayerName = CclParseNumberDesc(l);
 		} else {
 			lua_pop(l, 1);
-			LuaError(l, "unknow condition '%s'"_C_ key);
+			LuaError(l, "unknow condition '%s'" _C_ key);
 		}
 	} else {
 		LuaError(l, "Parse Error in ParseString");
