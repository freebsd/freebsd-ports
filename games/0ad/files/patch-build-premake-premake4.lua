--- build/premake/premake4.lua.orig	2013-03-07 14:49:49.000000000 +0100
+++ build/premake/premake4.lua	2013-04-03 00:14:47.033326555 +0200
@@ -136,7 +136,7 @@
 
 function project_set_build_flags()
 
-	flags { "Symbols", "NoEditAndContinue" }
+	flags { "NoEditAndContinue" }
 	if not _OPTIONS["icc"] and (os.is("windows") or not _OPTIONS["minimal-flags"]) then
 		-- adds the -Wall compiler flag
 		flags { "ExtraWarnings" } -- this causes far too many warnings/remarks on ICC
@@ -217,7 +217,6 @@
 
 					-- enable security features (stack checking etc) that shouldn't have
 					-- a significant effect on performance and can catch bugs
-					"-fstack-protector-all",
 					"-D_FORTIFY_SOURCE=2",
 
 					-- always enable strict aliasing (useful in debug builds because of the warnings)
@@ -343,11 +342,11 @@
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
 
