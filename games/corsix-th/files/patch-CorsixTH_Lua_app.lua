--- CorsixTH/Lua/app.lua.orig	2021-06-17 02:16:54 UTC
+++ CorsixTH/Lua/app.lua
@@ -64,7 +64,7 @@ function App:App()
   }
   self.strings = {}
   self.savegame_version = SAVEGAME_VERSION
-  self.check_for_updates = true
+  self.check_for_updates = false
 end
 
 --! Starts a Lua DBGp client & connects it to a DBGp server.
