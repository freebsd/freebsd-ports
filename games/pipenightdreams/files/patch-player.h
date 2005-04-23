--- src/player.h.orig	Sat Apr 23 14:01:47 2005
+++ src/player.h	Sat Apr 23 14:01:49 2005
@@ -47,8 +47,8 @@
     void setStartRowColumn(int row, int column);
     void setBoard(Board * bd);
 
-    inline void setRestrictionCoef(unsigned int coef);
-    inline void setFixedCoef(unsigned int coef);
+    void setRestrictionCoef(unsigned int coef);
+    void setFixedCoef(unsigned int coef);
 
     void incLives();
     void decLives();
