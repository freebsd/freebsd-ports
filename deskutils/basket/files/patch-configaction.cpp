--- basket/configaction.cpp.orig	Mon Sep  8 19:22:28 2003
+++ basket/configaction.cpp	Mon Sep  8 19:22:55 2003
@@ -38,16 +38,6 @@
 {
 }
 
-int ConfigAction::action()
-{
-	return m_action;
-}
-
-QString ConfigAction::runCommand()
-{
-	return m_runCommand;
-}
-
 void ConfigAction::setAction(int action)
 {
 	m_action = action;
