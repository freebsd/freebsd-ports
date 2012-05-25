--- build/premake/premake4.lua.orig	2012-02-21 21:27:25.000000000 +0100
+++ build/premake/premake4.lua	2012-05-17 23:23:30.211530880 +0200
@@ -215,7 +215,6 @@
 
 				-- enable security features (stack checking etc) that shouldn't have
 				-- a significant effect on performance and can catch bugs
-				"-fstack-protector-all",
 				"-D_FORTIFY_SOURCE=2",
 
 				-- always enable strict aliasing (useful in debug builds because of the warnings)
@@ -276,11 +275,11 @@
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
