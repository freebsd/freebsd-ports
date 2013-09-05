--- build/premake/premake4.lua.orig	2013-08-27 04:42:56.000000000 +0200
+++ build/premake/premake4.lua	2013-09-03 15:32:07.321963983 +0200
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
 
