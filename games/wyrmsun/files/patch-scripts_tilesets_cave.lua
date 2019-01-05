--- scripts/tilesets/cave.lua.orig	2018-12-25 12:18:32 UTC
+++ scripts/tilesets/cave.lua
@@ -165,4 +165,6 @@ BuildTilesetTables()
 
 Load("scripts/scripts.lua")
 GameSettings.Inside = true
-SetTimeOfDaySchedule("")
+if (LoadedGame == false) then
+	SetTimeOfDaySchedule("")
+end
