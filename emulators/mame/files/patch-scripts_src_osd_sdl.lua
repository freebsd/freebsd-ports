 Reduce noise in the build log, and remove legacy or incompatible display
 server lib directory declarations.

--- scripts/src/osd/sdl.lua.orig	2023-10-23 15:53:41 UTC
+++ scripts/src/osd/sdl.lua
@@ -276,12 +276,12 @@ if BASE_TARGETOS=="unix" then
 	else
 		if _OPTIONS["NO_X11"]=="1" then
 			_OPTIONS["USE_QTDEBUG"] = "0"
-		else
-			libdirs {
-				"/usr/X11/lib",
-				"/usr/X11R6/lib",
-				"/usr/openwin/lib",
-			}
+--		else
+--			libdirs {
+--				"/usr/X11/lib",
+--				"/usr/X11R6/lib",
+--				"/usr/openwin/lib",
+--			}
 		end
 		local str = backtick(sdlconfigcmd() .. " --libs")
 		addlibfromstring(str)
