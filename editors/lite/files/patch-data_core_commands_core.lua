--- data/core/commands/core.lua.orig	2021-01-09 16:02:57 UTC
+++ data/core/commands/core.lua
@@ -85,7 +85,7 @@ command.add(nil, {
   end,
 
   ["core:open-user-module"] = function()
-    core.root_view:open_doc(core.open_doc(EXEDIR .. "/data/user/init.lua"))
+    core.root_view:open_doc(core.open_doc(DATADIR .. "/user/init.lua"))
   end,
 
   ["core:open-project-module"] = function()
