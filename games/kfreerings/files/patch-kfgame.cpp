--- src/kfgame.cpp.orig	Sat Aug 21 10:04:02 2004
+++ src/kfgame.cpp	Sat Aug 21 10:04:39 2004
@@ -57,7 +57,7 @@
 }
 QPtrList<KFLevel>& KFGame::levelList() {
 	return m_gameHistory;
-};
+}
 
 void KFGame::startLevel( int level, int moves ) {
 	m_reachedLevel = -1;
