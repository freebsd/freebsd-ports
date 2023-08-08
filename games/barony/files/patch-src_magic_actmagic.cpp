--- src/magic/actmagic.cpp.orig	2022-10-30 19:00:46 UTC
+++ src/magic/actmagic.cpp
@@ -513,7 +513,7 @@ void actMagicMissile(Entity* my)   //TODO: Verify this
 					my->x = my->actmagicOrbitStationaryX + my->actmagicOrbitStationaryCurrentDist * cos(my->yaw);
 					my->y = my->actmagicOrbitStationaryY + my->actmagicOrbitStationaryCurrentDist * sin(my->yaw);
 					my->actmagicOrbitStationaryCurrentDist =
-						std::min(my->actmagicOrbitStationaryCurrentDist + 0.5, static_cast<real_t>(my->actmagicOrbitDist));
+						std::min(my->actmagicOrbitStationaryCurrentDist + (real_t)0.5, static_cast<real_t>(my->actmagicOrbitDist));
 				}
 				hitFromAbove = my->magicOrbitingCollision();
 				my->z += my->vel_z * my->actmagicOrbitVerticalDirection;
@@ -522,9 +522,9 @@ void actMagicMissile(Entity* my)   //TODO: Verify this
 				{
 					// we don't change direction, upwards we go!
 					// target speed is actmagicOrbitVerticalSpeed.
-					my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / 0.95);
+					my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / (real_t)0.95);
 					my->roll += (PI / 8) / (turnRate / my->vel_z) * my->actmagicOrbitVerticalDirection;
-					my->roll = std::max(my->roll, -PI / 4);
+					my->roll = std::max(my->roll, (real_t)-PI / 4);
 				}
 				else if ( my->z > my->actmagicOrbitStartZ )
 				{
@@ -535,7 +535,7 @@ void actMagicMissile(Entity* my)   //TODO: Verify this
 					}
 					else
 					{
-						my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / 0.95);
+						my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / (real_t)0.95);
 						my->roll += (PI / 8) / (turnRate / my->vel_z) * my->actmagicOrbitVerticalDirection;
 					}
 				}
@@ -543,7 +543,7 @@ void actMagicMissile(Entity* my)   //TODO: Verify this
 				{
 					if ( my->actmagicOrbitVerticalDirection == 1 )
 					{
-						my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / 0.95);
+						my->vel_z = std::min(my->actmagicOrbitVerticalSpeed, my->vel_z / (real_t)0.95);
 						my->roll += (PI / 8) / (turnRate / my->vel_z) * my->actmagicOrbitVerticalDirection;
 					}
 					else
@@ -3733,7 +3733,7 @@ void actParticleTimer(Entity* my)
 						int durationToStun = 0;
 						if ( distance >= 2 )
 						{
-							durationToStun = 25 + std::min((distance - 4) * 10, 50.0);
+							durationToStun = 25 + std::min((distance - 4) * 10, (real_t)50.0);
 						}
 						if ( target->behavior == &actMonster )
 						{
@@ -5616,4 +5616,4 @@ void magicDig(Entity* parent, Entity* projectile, int 
 			boulderSokobanOnDestroy(false);
 		}
 	}
-}
\ No newline at end of file
+}
