--- build/premake/extern_libs5.lua.orig	2025-12-22 03:23:46 UTC
+++ build/premake/extern_libs5.lua
@@ -221,7 +221,7 @@ extern_lib_defs = {
 			end
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.istarget("bsd") then
-				externalincludedirs { "/usr/local/include" }
+				externalincludedirs { "%%LOCALBASE%%/include" }
 			end
 		end,
 	},
