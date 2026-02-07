--- build/premake/premake5.lua.orig	2025-01-28 19:57:28 UTC
+++ build/premake/premake5.lua
@@ -85,14 +85,10 @@ else
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
 	-- TODO: We should look into "universal" macOS compilation.
 	if os.istarget("macosx") then
