--- src/monster_sentrybot.cpp.orig	2022-10-30 18:38:58 UTC
+++ src/monster_sentrybot.cpp
@@ -883,7 +883,7 @@ void sentryBotAnimate(Entity* my, Stat* myStats, doubl
 				entity->z += limbs[race][10][2];
 				if ( my->monsterAttack == MONSTER_POSE_RANGED_SHOOT1 )
 				{
-					entity->fskill[0] = std::min(3.5, 2 + entity->fskill[0]);
+					entity->fskill[0] = std::min((real_t)3.5, 2 + entity->fskill[0]);
 					entity->focalx += entity->fskill[0];
 				}
 				else
@@ -2227,4 +2227,4 @@ void Entity::tinkerBotSetStats(Stat* myStats, int rank
 	myStats->MAXHP = myStats->HP;
 	myStats->OLDHP = myStats->HP;
 	return;
-}
\ No newline at end of file
+}
