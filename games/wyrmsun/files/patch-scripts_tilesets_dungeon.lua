--- scripts/tilesets/dungeon.lua.orig	2018-12-25 12:18:32 UTC
+++ scripts/tilesets/dungeon.lua
@@ -216,4 +216,6 @@ BuildTilesetTables()
 
 Load("scripts/scripts.lua")
 GameSettings.Inside = true
-SetTimeOfDaySchedule("")
+if (LoadedGame == false) then
+	SetTimeOfDaySchedule("")
+end
