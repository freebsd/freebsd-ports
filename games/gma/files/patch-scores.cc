--- src/scores.cc.orig	Sun May 18 19:20:37 2003
+++ src/scores.cc	Sun May 18 19:20:51 2003
@@ -50,7 +50,7 @@
   return result;
 }
 
-void Scores::mark_good(const Pattern pattern, int goodness = 1)
+void Scores::mark_good(const Pattern pattern, int goodness)
 {
   // Mark this position as beneficial
   int i;
