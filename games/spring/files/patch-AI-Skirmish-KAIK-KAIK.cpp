--- AI/Skirmish/KAIK/KAIK.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/KAIK.cpp	2013-11-11 03:15:53.601773605 +0400
@@ -194,13 +194,13 @@
 void CKAIK::EnemyDestroyed(int enemyUnitID, int attackerUnitID) {
 	if (ai->Initialized()) {
 		ai->dgunConHandler->NotifyEnemyDestroyed(enemyUnitID, attackerUnitID);
-		ai->tm->EnemyDestroyed(enemyUnitID, attackerUnitID);
+		ai->thm->EnemyDestroyed(enemyUnitID, attackerUnitID);
 	}
 }
 
 void CKAIK::EnemyDamaged(int enemyUnitID, int attackerUnitID, float damage, float3 dir) {
 	if (ai->Initialized()) {
-		ai->tm->EnemyDamaged(enemyUnitID, attackerUnitID);
+		ai->thm->EnemyDamaged(enemyUnitID, attackerUnitID);
 
 		damage = damage;
 		dir = dir;
@@ -209,12 +209,12 @@
 
 void CKAIK::EnemyCreated(int enemyUnitID) {
 	if (ai->Initialized()) {
-		ai->tm->EnemyCreated(enemyUnitID);
+		ai->thm->EnemyCreated(enemyUnitID);
 	}
 }
 void CKAIK::EnemyFinished(int enemyUnitID) {
 	if (ai->Initialized()) {
-		ai->tm->EnemyFinished(enemyUnitID);
+		ai->thm->EnemyFinished(enemyUnitID);
 	}
 }
 
@@ -229,7 +229,7 @@
 		}
 
 		if ((msg = strstr(msg, "ThreatMap::DBG")) != NULL) {
-			ai->tm->ToggleVisOverlay();
+			ai->thm->ToggleVisOverlay();
 		}
 	}
 }
@@ -298,7 +298,7 @@
 		ai->dgunConHandler->Update(frame);
 
 		if ((frame - ai->InitFrame()) == 1) {
-			// ai->tm->Init();
+			// ai->thm->Init();
 			ai->dm->Init();
 		}
 
