--- src/p_enemy.cc.orig	2011-03-31 12:12:40 UTC
+++ src/p_enemy.cc
@@ -528,7 +528,7 @@ void P_FreeShootSpots(void)
 	if (brain_spots.number < 0)
 		return;
 
-	if (brain_spots.targets > 0)
+	if (brain_spots.targets)
 	{
 		SYS_ASSERT(brain_spots.targets);
 
