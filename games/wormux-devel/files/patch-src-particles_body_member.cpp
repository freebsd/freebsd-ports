--- src/particles/body_member.cpp	2007/07/30 00:32:42
+++ src/particles/body_member.cpp	2007/08/18 07:50:31
@@ -44,8 +44,7 @@
 {
   m_left_time_to_live--;
   UpdatePosition();
-  Point2d speed;
-  GetSpeedXY(speed);
+  Point2d speed = GetSpeedXY();
 
   angle_rad += speed.Norm() * 20;
   angle_rad = fmod(angle_rad, 2 *M_PI);
