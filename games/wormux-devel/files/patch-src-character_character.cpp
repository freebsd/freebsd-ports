--- src/character/character.cpp	2007/08/17 23:39:31
+++ src/character/character.cpp	2007/08/18 07:50:31
@@ -588,8 +588,7 @@
     static double speed_init = GameMode::GetInstance()->character.back_jump_strength *
        sin(GameMode::GetInstance()->character.back_jump_angle);

-    Point2d speed;
-    GetSpeedXY(speed);
+    Point2d speed = GetSpeedXY();
     rotation = M_PI * speed.y / speed_init;
     body->SetRotation(rotation);
   }
@@ -637,7 +636,7 @@
   if (IsDead()) return;

   pause_bouge_dg = Time::GetInstance()->Read();
-  double norme, degat;
+  double norm, degat;
   Point2d speed_vector;
   GameMode * game_mode = GameMode::GetInstance();
   if(body->GetClothe() != "weapon-" + m_team.GetWeapon().GetID()
@@ -651,12 +650,12 @@
   body->SetRotation(0.0);
   back_jumping = false;

-  GetSpeedXY (speed_vector);
-  norme = speed_vector.Norm();
-  if (norme > game_mode->safe_fall && speed_vector.y>0.0)
+  speed_vector= GetSpeedXY();
+  norm = speed_vector.Norm();
+  if (norm > game_mode->safe_fall && speed_vector.y>0.0)
   {
-    norme -= game_mode->safe_fall;
-    degat = norme * game_mode->damage_per_fall_unit;
+    norm -= game_mode->safe_fall;
+    degat = norm * game_mode->damage_per_fall_unit;
     SetEnergyDelta (-(int)degat);
     GameLoop::GetInstance()->SignalCharacterDamage(this);
     SetClothe("normal");

