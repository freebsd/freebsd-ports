 Remove suffixes from mame binary for debug/profile builds.

--- scripts/src/main.lua.orig	2025-09-24 14:56:11 UTC
+++ scripts/src/main.lua
@@ -71,13 +71,13 @@ end
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
