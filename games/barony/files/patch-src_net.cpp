--- src/net.cpp.orig	2022-10-30 17:24:45 UTC
+++ src/net.cpp
@@ -4212,7 +4212,7 @@ void clientHandlePacket()
 		if ( players[clientnum] && players[clientnum]->entity && stats[clientnum] )
 		{
 			real_t vel = sqrt(pow(players[clientnum]->entity->vel_y, 2) + pow(players[clientnum]->entity->vel_x, 2));
-			players[clientnum]->entity->monsterKnockbackVelocity = std::min(2.25, std::max(1.0, vel));
+			players[clientnum]->entity->monsterKnockbackVelocity = std::min((real_t)2.25, std::max((real_t)1.0, vel));
 			players[clientnum]->entity->monsterKnockbackTangentDir = atan2(players[clientnum]->entity->vel_y, players[clientnum]->entity->vel_x);
 			if ( vel < 0.01 )
 			{
