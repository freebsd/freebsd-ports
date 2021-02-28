--- build/premake/extern_libs5.lua.orig	2021-02-06 00:32:37 UTC
+++ build/premake/extern_libs5.lua
@@ -193,7 +193,7 @@ extern_lib_defs = {
 			end
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.istarget("bsd") then
-				sysincludedirs { "/usr/local/include" }
+				sysincludedirs { "%%LOCALBASE%%/include" }
 			end
 		end,
 		link_settings = function()
