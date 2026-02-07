 Reduce noise in the build log, remove legacy or incompatible display
 server include declarations, and redundant system include handled by Ports.
 Enable the build to find Qt-6, and remove redundant internal library.

--- scripts/src/osd/sdl_cfg.lua.orig	2023-11-10 07:57:09 UTC
+++ scripts/src/osd/sdl_cfg.lua
@@ -44,9 +44,6 @@ else
 		"SDLMAME_X11",
 	}
 	includedirs {
-		"/usr/X11/include",
-		"/usr/X11R6/include",
-		"/usr/openwin/include",
 	}
 end
 
@@ -144,7 +141,7 @@ elseif _OPTIONS["targetos"]=="linux" then
 elseif _OPTIONS["targetos"]=="linux" then
 	if _OPTIONS["QT_HOME"]~=nil then
 		buildoptions {
-			"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_INSTALL_HEADERS"),
+			"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake6 -query QT_INSTALL_HEADERS"),
 		}
 	else
 		buildoptions {
@@ -158,19 +155,12 @@ elseif _OPTIONS["targetos"]=="freebsd" then
 	}
 elseif _OPTIONS["targetos"]=="freebsd" then
 	buildoptions {
-		-- /usr/local/include is not considered a system include director on FreeBSD.  GL.h resides there and throws warnings
-		"-isystem /usr/local/include",
 	}
 end
 
 configuration { "osx*" }
 	includedirs {
 		MAME_DIR .. "3rdparty/bx/include/compat/osx",
-	}
-
-configuration { "freebsd" }
-	includedirs {
-		MAME_DIR .. "3rdparty/bx/include/compat/freebsd",
 	}
 
 configuration { "netbsd" }
