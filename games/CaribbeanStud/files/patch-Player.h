--- Player.h.orig	Tue Aug 19 12:00:36 2003
+++ Player.h	Tue Aug 19 12:01:09 2003
@@ -72,7 +72,7 @@
       int     _lastWinLost;
 };
 
-inline Player::WinLost( ) const
+inline int Player::WinLost( ) const
 {
 	 return _lastWinLost;
 }
