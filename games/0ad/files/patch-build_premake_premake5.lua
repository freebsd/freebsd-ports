--- build/premake/premake5.lua.orig	2022-09-23 19:16:45 UTC
+++ build/premake/premake5.lua
@@ -76,14 +76,10 @@ else
 	end
 else
 	local machine = "x86_64"
-	if os.getenv("HOSTTYPE") and os.getenv("HOSTTYPE") ~= '' then
-		machine = os.getenv("HOSTTYPE")
-	else
-		os.execute(cc .. " -dumpmachine > .gccmachine.tmp")
-		local f = io.open(".gccmachine.tmp", "r")
-		machine = f:read("*line")
-		f:close()
-	end
+	os.execute(cc .. " -dumpmachine > .gccmachine.tmp")
+	local f = io.open(".gccmachine.tmp", "r")
+	machine = f:read("*line")
+	f:close()
 	-- Special handling on mac os where xcode needs special flags.
 	if os.istarget("macosx") then
 		if string.find(machine, "arm64") then
@@ -380,7 +376,7 @@ function project_set_build_flags()
 
 		if os.istarget("linux") or os.istarget("bsd") then
 			if _OPTIONS["prefer-local-libs"] then
-				libdirs { "/usr/local/lib" }
+				libdirs { "%%LOCALBASE%%/lib" }
 			end
 
 			-- To use our local shared libraries, they need to be found in the
