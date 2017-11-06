--- build/premake/premake4.lua.orig	2017-07-06 17:29:49 UTC
+++ build/premake/premake4.lua
@@ -388,11 +388,11 @@ function project_add_x11_dirs()
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
 
