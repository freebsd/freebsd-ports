--- src/weapon/mine.cpp	2007/08/08 19:24:24
+++ src/weapon/mine.cpp	2007/08/18 07:50:31
@@ -218,15 +218,14 @@
   return true;
 }
 
-void Mine::Add (int x, int y)
+void Mine::Add(int x, int y)
 {
-  projectile -> SetXY ( Point2i(x, y) );
-  projectile -> SetOverlappingObject(&ActiveCharacter());
+  projectile->SetXY(Point2i(x, y));
+  projectile->SetOverlappingObject(&ActiveCharacter());
 
-  Point2d speed_vector;
-  ActiveCharacter().GetSpeedXY(speed_vector);
-  projectile -> SetSpeedXY (speed_vector);
-  lst_objects.AddObject (projectile);
+  Point2d speed_vector = ActiveCharacter().GetSpeedXY();
+  projectile->SetSpeedXY(speed_vector);
+  lst_objects.AddObject(projectile);
   projectile = NULL;
   ReloadLauncher();
 }
