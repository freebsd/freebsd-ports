--- CorsixTH/Lua/config_finder.lua.orig	2019-05-24 00:36:47 UTC
+++ CorsixTH/Lua/config_finder.lua
@@ -137,7 +137,7 @@ local config_defaults = {
   shift_scroll_speed = 4,
   new_graphics_folder = nil,
   use_new_graphics = false,
-  check_for_updates = true,
+  check_for_updates = false,
 }
 
 fi = io.open(config_filename, "r")
