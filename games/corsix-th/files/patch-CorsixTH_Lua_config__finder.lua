--- CorsixTH/Lua/config_finder.lua.orig	2015-08-30 20:29:45 UTC
+++ CorsixTH/Lua/config_finder.lua
@@ -133,7 +133,7 @@ local config_defaults = {
   shift_scroll_speed = 4,
   new_graphics_folder = nil,
   use_new_graphics = false,
-  check_for_updates = true
+  check_for_updates = false
 }
 local fi = io.open(config_filename, "r")
 local config_values = {}
