--- server/plugins/UIUGens.cpp.orig	2017-03-20 15:18:39 UTC
+++ server/plugins/UIUGens.cpp
@@ -415,7 +415,7 @@ void cmdDemoFunc(World *inWorld, void* inUserData, str
  */
 
 
-thread uiListenThread;
+std::thread uiListenThread;
 
 PluginLoad(UIUGens)
 {
