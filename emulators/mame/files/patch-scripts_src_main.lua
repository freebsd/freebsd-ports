 Remove suffixes from mame binary for debug/profile builds.

--- scripts/src/main.lua.orig	2023-11-14 03:17:20 UTC
+++ scripts/src/main.lua
@@ -58,13 +58,13 @@ end
 	configuration { "Release" }
 		targetsuffix ""
 		if _OPTIONS["PROFILE"] then
-			targetsuffix "p"
+			targetsuffix ""
 		end
 
 	configuration { "Debug" }
-		targetsuffix "d"
+		targetsuffix ""
 		if _OPTIONS["PROFILE"] then
-			targetsuffix "dp"
+			targetsuffix ""
 		end
 
 	configuration { "mingw*" or "vs20*" }
