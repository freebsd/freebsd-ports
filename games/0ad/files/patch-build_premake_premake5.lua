--- build/premake/premake5.lua.orig	2021-07-27 21:57:08 UTC
+++ build/premake/premake5.lua
@@ -367,7 +367,7 @@ function project_set_build_flags()
 
 		if os.istarget("linux") or os.istarget("bsd") then
 			if _OPTIONS["prefer-local-libs"] then
-				libdirs { "/usr/local/lib" }
+				libdirs { "%%LOCALBASE%%/lib" }
 			end
 
 			-- To use our local shared libraries, they need to be found in the
