--- build/premake/premake4.lua.orig	2012-10-30 01:56:24.000000000 +0100
+++ build/premake/premake4.lua	2012-12-26 18:37:28.882327928 +0100
@@ -134,7 +134,7 @@
 
 function project_set_build_flags()
 
-	flags { "Symbols", "NoEditAndContinue" }
+	flags { "NoEditAndContinue" }
 	if not _OPTIONS["icc"] and (os.is("windows") or not _OPTIONS["minimal-flags"]) then
 		-- adds the -Wall compiler flag
 		flags { "ExtraWarnings" } -- this causes far too many warnings/remarks on ICC
@@ -215,7 +215,6 @@
 
 					-- enable security features (stack checking etc) that shouldn't have
 					-- a significant effect on performance and can catch bugs
-					"-fstack-protector-all",
 					"-D_FORTIFY_SOURCE=2",
 
 					-- always enable strict aliasing (useful in debug builds because of the warnings)
@@ -287,11 +286,11 @@
 		-- X11 includes may be installed in one of a gadzillion of three places
 		-- Famous last words: "You can't include too much! ;-)"
 		includedirs {
-			"/usr/X11R6/include/X11",
-			"/usr/X11R6/include",
+			"/usr/local/X11",
+			"/usr/local/include",
 			"/usr/include/X11"
 		}
-		libdirs { "/usr/X11R6/lib" }
+		libdirs { "/usr/local/lib" }
 
 		if _OPTIONS["bindir"] then
 			defines { "INSTALLED_BINDIR=" .. _OPTIONS["bindir"] }
