--- build/premake/extern_libs4.lua.orig	2014-09-24 10:05:27 UTC
+++ build/premake/extern_libs4.lua
@@ -237,7 +237,7 @@
 			end
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.is("bsd") then
-				includedirs { "/usr/local/include" }
+				includedirs { "%%LOCALBASE%%/include" }
 			end
 		end,
 		link_settings = function()
