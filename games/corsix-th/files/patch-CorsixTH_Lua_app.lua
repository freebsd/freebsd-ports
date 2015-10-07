--- CorsixTH/Lua/app.lua.orig	2015-08-30 20:29:45 UTC
+++ CorsixTH/Lua/app.lua
@@ -63,7 +63,7 @@ function App:App()
   }
   self.strings = {}
   self.savegame_version = SAVEGAME_VERSION
-  self.check_for_updates = true
+  self.check_for_updates = false
 end
 
 --! Starts a Lua DBGp client & connects it to a DBGp server.
