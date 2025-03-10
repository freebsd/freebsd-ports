--- build/premake/extern_libs5.lua.orig	2025-01-28 19:57:28 UTC
+++ build/premake/extern_libs5.lua
@@ -232,9 +232,9 @@ extern_lib_defs = {
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.istarget("bsd") then
 				if externalincludedirs then
-					externalincludedirs { "/usr/local/include" }
+					externalincludedirs { "%%LOCALBASE%%/include" }
 				else
-					sysincludedirs { "/usr/local/include" }
+					sysincludedirs { "%%LOCALBASE%%/include" }
 				end
 			end
 		end,
