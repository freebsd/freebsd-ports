--- src/actarrow.cpp.orig	2022-10-30 18:44:49 UTC
+++ src/actarrow.cpp
@@ -257,14 +257,14 @@ void actArrow(Entity* my)
 				{
 					ARROW_VELZ += my->arrowFallSpeed;
 					my->z += ARROW_VELZ;
-					my->pitch = std::min(my->pitch + pitchChange, PI / 8);
+					my->pitch = std::min(my->pitch + pitchChange, (real_t)PI / 8);
 				}
 			}
 			else
 			{
 				ARROW_VELZ += my->arrowFallSpeed;
 				my->z += ARROW_VELZ;
-				my->pitch = std::min(my->pitch + pitchChange, PI / 8);
+				my->pitch = std::min(my->pitch + pitchChange, (real_t)PI / 8);
 			}
 		}
 
@@ -511,7 +511,7 @@ void actArrow(Entity* my)
 					real_t damageMultiplier = hit.entity->getDamageTableMultiplier(*hitstats, DAMAGE_TABLE_RANGED);
 					if ( huntingDamage || silverDamage )
 					{
-						damageMultiplier = std::max(0.75, damageMultiplier);
+						damageMultiplier = std::max((real_t)0.75, damageMultiplier);
 					}
 
 					if ( hitWeaklyOnTarget )
