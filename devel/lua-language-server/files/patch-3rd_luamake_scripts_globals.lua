--- 3rd/luamake/scripts/globals.lua.orig	2025-12-08 19:07:07 UTC
+++ 3rd/luamake/scripts/globals.lua
@@ -8,6 +8,8 @@ globals.mode = globals.mode or "release"
 
 globals.mode = globals.mode or "release"
 
+globals.ninja = globals.ninja or "%NINJA_CMD%"
+
 globals.hostos = globals.hostos or require "bee.platform".os
 globals.hostshell = globals.hostshell or (function ()
     if globals.hostos == "windows" then
