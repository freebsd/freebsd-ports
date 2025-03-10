--- scene.cpp.orig	2024-11-06 19:04:58 UTC
+++ scene.cpp
@@ -2361,7 +2361,7 @@ void Scene::menuIdle() 
 	oldTimer = newTimer;
 	globalList->move()	;
 #ifndef PI
-#define PI=3.151592653589793
+#define PI=3.141592653589793
 #endif
 	benchFrames++;
 
