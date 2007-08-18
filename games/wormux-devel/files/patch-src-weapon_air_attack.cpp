--- src/weapon/air_attack.cpp	2007/08/08 19:24:24
+++ src/weapon/air_attack.cpp	2007/08/18 07:50:31
@@ -137,8 +137,7 @@
   Obus * instance = new Obus(cfg);
   instance->SetXY(Point2i(GetX(), obus_dy) );
 
-  Point2d speed_vector;
-  GetSpeedXY(speed_vector);
+  Point2d speed_vector = GetSpeedXY();
 
   int fx = randomSync.GetLong(FORCE_X_MIN, FORCE_X_MAX);
   fx *= GetDirection();
