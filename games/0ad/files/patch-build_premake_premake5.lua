--- build/premake/premake5.lua.orig	2021-02-06 00:32:37 UTC
+++ build/premake/premake5.lua
@@ -365,7 +365,7 @@ function project_set_build_flags()
 
 		if os.istarget("linux") or os.istarget("bsd") then
 			if _OPTIONS["prefer-local-libs"] then
-				libdirs { "/usr/local/lib" }
+				libdirs { "%%LOCALBASE%%/lib" }
 			end
 
 			-- To use our local shared libraries, they need to be found in the
