--- CorsixTH/Lua/app.lua.orig	2023-06-25 00:50:42 UTC
+++ CorsixTH/Lua/app.lua
@@ -65,7 +65,7 @@ function App:App()
   }
   self.strings = {}
   self.savegame_version = SAVEGAME_VERSION
-  self.check_for_updates = true
+  self.check_for_updates = false
   self.idle_tick = 0
 end
 
