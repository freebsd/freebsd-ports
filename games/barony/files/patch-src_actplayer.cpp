--- src/actplayer.cpp.orig	2022-10-30 17:34:26 UTC
+++ src/actplayer.cpp
@@ -791,7 +791,7 @@ void handlePlayerMovement(Entity* my, int playernum, b
 		}
 		else if ( stats[PLAYER_NUM]->EFFECTS[EFF_KNOCKBACK] )
 		{
-			speedFactor = std::min(speedFactor, 5.0);
+			speedFactor = std::min(speedFactor, (real_t)5.0);
 			PLAYER_VELX += my->monsterKnockbackVelocity * cos(my->monsterKnockbackTangentDir) * refreshRateDelta;
 			PLAYER_VELY += my->monsterKnockbackVelocity * sin(my->monsterKnockbackTangentDir) * refreshRateDelta;
 			my->monsterKnockbackVelocity *= pow(0.95, refreshRateDelta);
@@ -6634,7 +6634,7 @@ void playerAnimateSpider(Entity* my)
 		if ( bodypart > 12 )
 		{
 			entity->pitch = -my->pitch;
-			entity->pitch = std::max(-PI / 32, std::min(PI / 32, entity->pitch));
+			entity->pitch = std::max((real_t)-PI / 32, std::min((real_t)PI / 32, entity->pitch));
 			if ( bodypart % 2 == 0 )
 			{
 				entity->sprite = 826;
@@ -6913,4 +6913,4 @@ void playerAnimateSpider(Entity* my)
 				break;
 		}
 	}
-}
\ No newline at end of file
+}
