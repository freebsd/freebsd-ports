--- ./Player.h.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Player.h	2013-10-29 15:12:13.000000000 -0200
@@ -72,7 +72,7 @@
       int     _lastWinLost;
 };
 
-inline Player::WinLost( ) const
+inline int Player::WinLost( ) const
 {
 	 return _lastWinLost;
 }
