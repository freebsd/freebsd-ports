--- src/eventmanager.cpp.orig	Sat Jan  1 14:52:51 2005
+++ src/eventmanager.cpp	Sat Jan  1 14:52:55 2005
@@ -40,7 +40,7 @@
   lista_streams->remove(lista_streams->indexOf(s));
 }
 
-void EventManager::pumpEvents(bool wait=false){
+void EventManager::pumpEvents(bool wait){
   SDL_Event event;
   Index * stream;
   bool got=false;
