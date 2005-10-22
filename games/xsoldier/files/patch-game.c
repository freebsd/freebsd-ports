
$FreeBSD$

--- game.c.orig
+++ game.c
@@ -275,24 +275,24 @@
               /* shoot down bonus message */
               if (manage->BossTime >= 1)
               {
-		sprintf(Percent,"shoot down %02d%%",player->Percent);
+		snprintf(Percent, sizeof(Percent), "shoot down %02d%%",player->Percent);
                 draw_string(210, 370, Percent, strlen(Percent));
 
 
-		sprintf(Bonus,"Bonus %d pts", shoot_down_bonus(player->Percent, manage->Loop, manage->Stage));
+		snprintf(Bonus, sizeof(Bonus), "Bonus %d pts", shoot_down_bonus(player->Percent, manage->Loop, manage->Stage));
                 draw_string(260 + manage->Appear*3 , 400,
                             Bonus, strlen(Bonus));
 
 		if (player->Percent >= 100)
 		{
-		    sprintf(Perfect,"Perfect!!");
+		    snprintf(Perfect, sizeof(Perfect), "Perfect!!");
                     draw_string(170 - manage->Appear*3 , 420,
                                 Perfect, strlen(Perfect));
 		}
               }
               else
               {
-                snprintf(Percent, 32, "the boss escaped");
+                snprintf(Percent, sizeof(Percent), "the boss escaped");
                 draw_string(200 ,370 ,Percent, strlen(Percent));
               }
               
@@ -335,19 +335,19 @@
     
     int i;
 
-    sprintf(Score,"Score % 8d",player->Rec[0].score);
-    sprintf(Stage,"Stage %2d",manage->Stage);
-    sprintf(Ships,"Ships %3d",player->Ships);
+    snprintf(Score, sizeof(Score), "Score % 8d",player->Rec[0].score);
+    snprintf(Stage, sizeof(Stage), "Stage %2d",manage->Stage);
+    snprintf(Ships, sizeof(Ships), "Ships %3d",player->Ships);
 #ifdef DEBUG
-    sprintf(ObjectE,"Enemy Object %3d",manage->EnemyNum);
-    sprintf(ObjectP,"Player Object %3d",manage->PlayerNum);
-    sprintf(Loop,"Loop %2d",manage->Loop);
-    sprintf(Level,"Level %3d",manage->Level);
-    sprintf(Weapon,"Weapon %d",manage->player[0]->Data.Cnt[5]);
-    sprintf(Pow,"Pow %2d",manage->player[0]->Data.Cnt[6]);
-    sprintf(Speed,"Speed %2d",manage->player[0]->Data.Speed);
-    sprintf(Enemy,"Enemy %3d",manage->StageEnemy);
-    sprintf(EnemyKill,"EnemyKill %3d",manage->StageShotDown);
+    snprintf(ObjectE, sizeof(ObjectE), "Enemy Object %3d",manage->EnemyNum);
+    snprintf(ObjectP, sizeof(ObjectP), "Player Object %3d",manage->PlayerNum);
+    snprintf(Loop, sizeof(Loop), "Loop %2d",manage->Loop);
+    snprintf(Level, sizeof(Level), "Level %3d",manage->Level);
+    snprintf(Weapon, sizeof(Weapon), "Weapon %d",manage->player[0]->Data.Cnt[5]);
+    snprintf(Pow, sizeof(Pow), "Pow %2d",manage->player[0]->Data.Cnt[6]);
+    snprintf(Speed, sizeof(Speed), "Speed %2d",manage->player[0]->Data.Speed);
+    snprintf(Enemy, sizeof(Enemy), "Enemy %3d",manage->StageEnemy);
+    snprintf(EnemyKill, sizeof(EnemyKill), "EnemyKill %3d",manage->StageShotDown);
 #endif
 
     draw_string(10, 20, Score, strlen(Score));
