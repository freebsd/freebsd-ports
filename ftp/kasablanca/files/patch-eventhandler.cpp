--- src/eventhandler.cpp.orig	Wed Jul 14 00:16:23 2004
+++ src/eventhandler.cpp	Wed Jul 14 00:27:52 2004
@@ -58,7 +58,7 @@
 
 bool EventHandler::eventFilter(QObject*, QEvent *e )
 {
-	EventType type = static_cast<EventType>(e->type());
+	EventType type = (EventType)(e->type());
 
 	if (mp_thread == NULL)
 	{
