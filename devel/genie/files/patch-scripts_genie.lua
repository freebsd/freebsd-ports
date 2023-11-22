--- scripts/genie.lua.orig	2023-09-20 17:46:05 UTC
+++ scripts/genie.lua
@@ -45,17 +45,12 @@ --
 			"../src/host/lua-5.3.0/etc/*.c",
 		}
 
-		buildoptions {
-			"-m64",
-		}
-
 		configuration "Debug"
 			defines     { "_DEBUG", "LUA_COMPAT_MODULE" }
 			flags       { "Symbols" }
 
 		configuration "Release"
 			defines     { "NDEBUG", "LUA_COMPAT_MODULE" }
-			flags       { "OptimizeSize" }
 
 		configuration "vs*"
 			defines     { "_CRT_SECURE_NO_WARNINGS" }
