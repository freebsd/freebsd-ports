--- src/kflevel.cpp.orig	Sat Aug 21 10:05:41 2004
+++ src/kflevel.cpp	Sat Aug 21 10:05:58 2004
@@ -79,13 +79,13 @@
 
 int KFLevel::getPoints() const {
 	return m_points;
-};
+}
 int KFLevel::getBonus() const {
 	return m_bonus;
-};
+}
 int KFLevel::getScore() const {
 	return m_points + m_bonus;
-};
+}
 int KFLevel::getMaxPoints() const{
 	switch ( m_skill ) {
 		case KFGame::CHILD:
