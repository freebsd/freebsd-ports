--- src/monster_lichfire.cpp.orig	2022-10-30 18:36:41 UTC
+++ src/monster_lichfire.cpp
@@ -756,10 +756,10 @@ void lichFireAnimate(Entity* my, Stat* myStats, double
 								{
 									if ( target )
 									{
-										real_t targetDist = std::min(entityDist(my, target), 32.0);
+										real_t targetDist = std::min(entityDist(my, target), (real_t)32.0);
 										for ( int i = 0; i < 8; ++i )
 										{
-											my->castFallingMagicMissile(SPELL_FIREBALL, std::max(targetDist - 8 + rand() % 8, 4.0), dir + i * PI / 4, 0);
+											my->castFallingMagicMissile(SPELL_FIREBALL, std::max(targetDist - 8 + rand() % 8, (real_t)4.0), dir + i * PI / 4, 0);
 										}
 									}
 									else
@@ -1304,4 +1304,4 @@ void Entity::lichFireSummonMonster(Monster creature)
 			serverSpawnMiscParticlesAtLocation(spawn_x, spawn_y, 0, PARTICLE_EFFECT_SUMMON_MONSTER, 174);
 		}
 	}
-}
\ No newline at end of file
+}
