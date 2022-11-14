--- src/actmonster.cpp.orig	2022-10-30 17:36:42 UTC
+++ src/actmonster.cpp
@@ -3457,7 +3457,7 @@ void actMonster(Entity* my)
 							real_t monsterVisionRange = sightranges[myStats->type];
 							if ( hitstats->type == DUMMYBOT )
 							{
-								monsterVisionRange = std::min(monsterVisionRange, 96.0);
+								monsterVisionRange = std::min(monsterVisionRange, (real_t)96.0);
 							}
 
 							if ( targetdist > monsterVisionRange )
@@ -4059,7 +4059,7 @@ void actMonster(Entity* my)
 				real_t monsterVisionRange = sightranges[myStats->type];
 				if ( hitstats && hitstats->type == DUMMYBOT )
 				{
-					monsterVisionRange = std::min(monsterVisionRange, 96.0);
+					monsterVisionRange = std::min(monsterVisionRange, (real_t)96.0);
 				}
 				if ( myStats->EFFECTS[EFF_FEAR] )
 				{
@@ -4846,7 +4846,7 @@ timeToGoAgain:
 							real_t monsterVisionRange = sightranges[myStats->type];
 							if ( hitstats->type == DUMMYBOT )
 							{
-								monsterVisionRange = std::min(monsterVisionRange, 96.0);
+								monsterVisionRange = std::min(monsterVisionRange, (real_t)96.0);
 							}
 
 							if ( targetdist > monsterVisionRange )
@@ -10466,19 +10466,19 @@ void Entity::monsterHandleKnockbackVelocity(real_t mon
 	
 	if ( maxVelX > 0 )
 	{
-		this->vel_x = std::min(this->vel_x + (this->monsterKnockbackVelocity * maxVelX), mobile ? maxVelX : 0.0);
+		this->vel_x = std::min(this->vel_x + (this->monsterKnockbackVelocity * maxVelX), mobile ? maxVelX : (real_t)0.0);
 	}
 	else
 	{
-		this->vel_x = std::max(this->vel_x + (this->monsterKnockbackVelocity * maxVelX), mobile ? maxVelX : 0.0);
+		this->vel_x = std::max(this->vel_x + (this->monsterKnockbackVelocity * maxVelX), mobile ? maxVelX : (real_t)0.0);
 	}
 	if ( maxVelY > 0 )
 	{
-		this->vel_y = std::min(this->vel_y + (this->monsterKnockbackVelocity * maxVelY), mobile ? maxVelY : 0.0);
+		this->vel_y = std::min(this->vel_y + (this->monsterKnockbackVelocity * maxVelY), mobile ? maxVelY : (real_t)0.0);
 	}
 	else
 	{
-		this->vel_y = std::max(this->vel_y + (this->monsterKnockbackVelocity * maxVelY), mobile ? maxVelY : 0.0);
+		this->vel_y = std::max(this->vel_y + (this->monsterKnockbackVelocity * maxVelY), mobile ? maxVelY : (real_t)0.0);
 	}
 	this->monsterKnockbackVelocity *= 1.1;
 }
@@ -10764,4 +10764,4 @@ bool Entity::isFollowerFreeToPathToPlayer(Stat* myStat
 		}
 	}
 	return true;
-}
\ No newline at end of file
+}
