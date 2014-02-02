--- ./src/eventmanager.cpp.orig	2002-01-17 20:56:26.000000000 +0100
+++ ./src/eventmanager.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -40,7 +40,7 @@
   lista_streams->remove(lista_streams->indexOf(s));
 }
 
-void EventManager::pumpEvents(bool wait=false){
+void EventManager::pumpEvents(bool wait){
   SDL_Event event;
   Index * stream;
   bool got=false;
