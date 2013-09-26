--- build/premake/premake4.lua.orig	2013-08-27 04:42:56.000000000 +0200
+++ build/premake/premake4.lua	2013-09-17 18:31:17.300814455 +0200
@@ -39,7 +39,7 @@
 	if arch == "x86_64" or arch == "amd64" then
 		arch = "amd64"
 	else
-		os.execute("gcc -dumpmachine > .gccmachine.tmp")
+		os.execute("%%CC%% -dumpmachine > .gccmachine.tmp")
 		local f = io.open(".gccmachine.tmp", "r")
 		local machine = f:read("*line")
 		f:close()
@@ -91,7 +91,7 @@
 	-- do the test in this build script instead (which is kind of ugly - please fix if
 	-- you have a better idea)
 	if not _OPTIONS["icc"] then
-		os.execute("gcc -dumpversion > .gccver.tmp")
+		os.execute("%%CC%% -dumpversion > .gccver.tmp")
 		local f = io.open(".gccver.tmp", "r")
 		major, dot, minor = f:read(1, 1, 1)
 		f:close()
@@ -138,7 +138,7 @@
 
 function project_set_build_flags()
 
-	flags { "Symbols", "NoEditAndContinue" }
+	flags { "NoEditAndContinue" }
 	if not _OPTIONS["icc"] and (os.is("windows") or not _OPTIONS["minimal-flags"]) then
 		-- adds the -Wall compiler flag
 		flags { "ExtraWarnings" } -- this causes far too many warnings/remarks on ICC
@@ -356,11 +356,11 @@
 		-- X11 includes may be installed in one of a gadzillion of three places
 		-- Famous last words: "You can't include too much! ;-)"
 		includedirs {
-			"/usr/X11R6/include/X11",
-			"/usr/X11R6/include",
+			"%%LOCALBASE%%/include/X11",
+			"%%LOCALBASE%%/include",
 			"/usr/include/X11"
 		}
-		libdirs { "/usr/X11R6/lib" }
+		libdirs { "%%LOCALBASE%%/lib" }
 	end
 end
 
