--- src/magic/castSpell.cpp.orig	2022-10-30 19:05:01 UTC
+++ src/magic/castSpell.cpp
@@ -1144,7 +1144,7 @@ Entity* castSpell(Uint32 caster_uid, spell_t* spell, b
 					else
 					{
 						real_t vel = sqrt(pow(caster->vel_y, 2) + pow(caster->vel_x, 2));
-						caster->monsterKnockbackVelocity = std::min(2.25, std::max(1.0, vel));
+						caster->monsterKnockbackVelocity = std::min((real_t)2.25, std::max((real_t)1.0, vel));
 						caster->monsterKnockbackTangentDir = atan2(caster->vel_y, caster->vel_x);
 						if ( vel < 0.01 )
 						{
@@ -2492,4 +2492,4 @@ bool spellIsNaturallyLearnedByRaceOrClass(Entity& cast
 	}
 
 	return false;
-}
\ No newline at end of file
+}
