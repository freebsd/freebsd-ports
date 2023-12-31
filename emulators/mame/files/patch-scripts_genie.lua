 Reduce noise from build logs, and remove duplicate use of
 -fno-strict-aliasing. Move a hard coded linktime optimisation to be covered by
 the same OPTIMIZE conditional used elsewhere.

--- scripts/genie.lua.orig	2023-11-15 01:11:29 UTC
+++ scripts/genie.lua
@@ -804,7 +804,6 @@ if _OPTIONS["OPTIMIZE"] then
 if _OPTIONS["OPTIMIZE"] then
 	buildoptions {
 		"-O".. _OPTIONS["OPTIMIZE"],
-		"-fno-strict-aliasing"
 	}
 	if _OPTIONS["OPT_FLAGS"] then
 		buildoptions {
@@ -1168,7 +1167,6 @@ configuration { "asmjs" }
 	}
 	linkoptions {
 		"-Wl,--start-group",
-		"-O" .. _OPTIONS["OPTIMIZE"],
 		"-s USE_SDL=2",
 		"-s USE_SDL_TTF=2",
 		"--memory-init-file 0",
@@ -1187,6 +1185,11 @@ configuration { "asmjs" }
 		"--embed-file " .. _MAKE.esc(MAME_DIR) .. "artwork/bgfx@artwork/bgfx",
 		"--embed-file " .. _MAKE.esc(MAME_DIR) .. "artwork/slot-mask.png@artwork/slot-mask.png",
 	}
+	if _OPTIONS["OPTIMIZE"] then
+		linkoptions {
+		"-O".. _OPTIONS["OPTIMIZE"],
+		}
+	end
 	if _OPTIONS["SYMBOLS"]~=nil and _OPTIONS["SYMBOLS"]~="0" then
 		linkoptions {
 			"-g" .. _OPTIONS["SYMLEVEL"],
