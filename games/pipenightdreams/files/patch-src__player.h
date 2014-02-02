--- ./src/player.h.orig	2002-01-17 20:56:40.000000000 +0100
+++ ./src/player.h	2014-02-01 23:41:06.000000000 +0100
@@ -47,8 +47,8 @@
     void setStartRowColumn(int row, int column);
     void setBoard(Board * bd);
 
-    inline void setRestrictionCoef(unsigned int coef);
-    inline void setFixedCoef(unsigned int coef);
+    void setRestrictionCoef(unsigned int coef);
+    void setFixedCoef(unsigned int coef);
 
     void incLives();
     void decLives();
