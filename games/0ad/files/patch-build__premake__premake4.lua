--- build/premake/premake4.lua.orig	2014-09-24 10:05:09 UTC
+++ build/premake/premake4.lua
@@ -416,11 +416,11 @@
 		includedirs {
 			"/usr/X11R6/include/X11",
 			"/usr/X11R6/include",
-			"/usr/local/include/X11",
-			"/usr/local/include",
+			"%%LOCALBASE%%/include/X11",
+			"%%LOCALBASE%%/include",
 			"/usr/include/X11"
 		}
-		libdirs { "/usr/X11R6/lib" }
+		libdirs { "%%LOCALBASE%%/lib" }
 	end
 end
 
