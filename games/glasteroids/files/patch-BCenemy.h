--- BCenemy.h.orig	Thu Dec 21 17:33:04 2006
+++ BCenemy.h	Thu Dec 21 17:33:15 2006
@@ -37,7 +37,7 @@
     void DrawEnemyShipExploding ( void );
     void ResetShip ( );
 
-    int BCenemy::GetStatus ( void );
+    int GetStatus ( void );
 
     BCship *Ship;
 
