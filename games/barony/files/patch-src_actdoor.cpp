--- src/actdoor.cpp.orig	2022-10-30 17:46:30 UTC
+++ src/actdoor.cpp
@@ -174,11 +174,11 @@ void actDoor(Entity* my)
 			// closing door
 			if ( my->yaw > my->doorStartAng )
 			{
-				my->yaw = std::max(my->doorStartAng, my->yaw - 0.15);
+				my->yaw = std::max(my->doorStartAng, my->yaw - (real_t)0.15);
 			}
 			else if ( my->yaw < my->doorStartAng )
 			{
-				my->yaw = std::min(my->doorStartAng, my->yaw + 0.15);
+				my->yaw = std::min(my->doorStartAng, my->yaw + (real_t)0.15);
 			}
 		}
 		else
