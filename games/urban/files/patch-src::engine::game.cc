--- src/engine/game.cc.orig	Mon Jun  7 17:20:59 1999
+++ src/engine/game.cc	Sun Jan 25 23:33:14 2004
@@ -93,10 +93,10 @@
 char *demo_filename;
 
 struct PlayerData DefaultPData = {
-	{3},
+	3,
 	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
-        {300}, {0}
+        300, 0
 };
 
 
