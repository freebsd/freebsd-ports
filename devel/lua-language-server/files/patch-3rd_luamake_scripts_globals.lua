--- 3rd/luamake/scripts/globals.lua.orig	2026-04-24 13:47:30 UTC
+++ 3rd/luamake/scripts/globals.lua
@@ -8,6 +8,9 @@ globals.mode = globals.mode or "release"
 
 globals.mode = globals.mode or "release"
 
+globals.ninja = globals.ninja or "%NINJA_CMD%"
+globals.cc = "%CC%"
+
 globals.hostos = globals.hostos or require "bee.platform".os
 globals.hostshell = globals.hostshell or (function ()
     if globals.hostos == "windows" then
