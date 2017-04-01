--- lang/LangPrimSource/OSCData.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/OSCData.cpp
@@ -1090,7 +1090,7 @@ int prQuitInProcessServer(VMGlobals *g, int numArgsPus
 		World *world = gInternalSynthServer.mWorld;
 		gInternalSynthServer.mWorld = 0;
 
-		thread thread(std::bind(World_WaitForQuit, world, false));
+		std::thread thread(std::bind(World_WaitForQuit, world, false));
 
 		thread.detach();
 	}
