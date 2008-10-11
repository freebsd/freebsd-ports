--- rts/Lua/LuaUtils.h.orig	2008-07-16 02:42:48.000000000 +0400
+++ rts/Lua/LuaUtils.h	2008-10-09 21:41:37.000000000 +0400
@@ -14,6 +14,8 @@
 #include "LuaDefs.h"
 #include "Sim/Units/CommandAI/Command.h"
 
+#undef isnumber
+
 class LuaUtils {
 	public:
 		static int CopyData(lua_State* dst, lua_State* src, int count);
