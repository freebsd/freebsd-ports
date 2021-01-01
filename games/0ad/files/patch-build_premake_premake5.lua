--- build/premake/premake5.lua.orig	2018-04-22 18:14:45 UTC
+++ build/premake/premake5.lua
@@ -376,11 +376,11 @@ function project_add_x11_dirs()
 		sysincludedirs {
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
 
