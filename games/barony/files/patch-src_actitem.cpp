--- src/actitem.cpp.orig	2022-10-30 17:39:42 UTC
+++ src/actitem.cpp
@@ -397,7 +397,7 @@ void actItem(Entity* my)
 			ITEM_VELZ += 0.04;
 			my->z += ITEM_VELZ;
 			my->roll += 0.02;
-			my->roll = std::min(my->roll, PI / 2);
+			my->roll = std::min(my->roll, (real_t)PI / 2);
 		}
 		else if ( my->sprite == items[TOOL_BOMB].index || my->sprite == items[TOOL_FREEZE_BOMB].index
 			|| my->sprite == items[TOOL_SLEEP_BOMB].index || my->sprite == items[TOOL_TELEPORT_BOMB].index
@@ -416,7 +416,7 @@ void actItem(Entity* my)
 			if ( my->roll > PI / 2 && my->roll < 3 * PI / 2 )
 			{
 				my->roll += 0.08;
-				my->roll = std::min(my->roll, 3 * PI / 2);
+				my->roll = std::min(my->roll, 3 * (real_t)PI / 2);
 			}
 			else
 			{
