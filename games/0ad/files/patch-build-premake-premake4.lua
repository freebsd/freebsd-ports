--- build/premake/premake4.lua.orig	2012-08-15 02:10:44.000000000 +0200
+++ build/premake/premake4.lua	2012-09-13 04:13:10.184743291 +0200
@@ -220,7 +220,6 @@
 
 					-- enable security features (stack checking etc) that shouldn't have
 					-- a significant effect on performance and can catch bugs
-					"-fstack-protector-all",
 					"-D_FORTIFY_SOURCE=2",
 
 					-- always enable strict aliasing (useful in debug builds because of the warnings)
@@ -292,11 +291,11 @@
 		-- X11 includes may be installed in one of a gadzillion of three places
 		-- Famous last words: "You can't include too much! ;-)"
 		includedirs {
-			"/usr/X11R6/include/X11",
-			"/usr/X11R6/include",
+			"%%LOCALBASE%%/X11",
+			"%%LOCALBASE%%/include",
 			"/usr/include/X11"
 		}
-		libdirs { "/usr/X11R6/lib" }
+		libdirs { "%%LOCALBASE%%/lib" }
 
 		if _OPTIONS["bindir"] then
 			defines { "INSTALLED_BINDIR=" .. _OPTIONS["bindir"] }
