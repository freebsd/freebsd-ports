--- ./hiscore.h.orig	2007-06-03 13:09:24.000000000 +0200
+++ ./hiscore.h	2013-10-17 23:37:42.000000000 +0200
@@ -28,7 +28,7 @@
     std::string name;
     int level;
     int points;
-    bool operator<(const HiScore& h) { return points > h.points; };
+    bool operator<(const HiScore& h) const { return points > h.points; };
 };
 //-----------------------------------------------------------------------------
 class HiScores
