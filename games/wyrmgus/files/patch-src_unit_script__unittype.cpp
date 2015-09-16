--- src/unit/script_unittype.cpp.orig	2015-06-01 15:35:14 UTC
+++ src/unit/script_unittype.cpp
@@ -1342,7 +1342,7 @@ static int CclDefineUnitType(lua_State *
 			type->Parent = LuaToString(l, -1);
 			CUnitType *parent_type = UnitTypeByIdent(type->Parent);
 			if (!parent_type) {
-				LuaError(l, "Unit type %s not defined" _C_ type->Parent);
+				LuaError(l, "Unit type %s not defined" _C_ type->Parent.c_str());
 			}
 			type->Class = parent_type->Class;
 			type->DrawLevel = parent_type->DrawLevel;
