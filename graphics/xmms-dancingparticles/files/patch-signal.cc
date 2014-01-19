--- signal.cc.orig
+++ signal.cc
@@ -24,7 +24,7 @@
 #include <SDL/SDL_thread.h>
 
 beatdetector detector;
-extern SDL_mutex *mutex;
+extern SDL_mutex *sdlmutex;
 
 beatdetector::beatdetector()
 {
@@ -93,7 +93,7 @@
 {
   int i;
   
-  SDL_mutexP(mutex);
+  SDL_mutexP(sdlmutex);
   
   for(i = 0; i < 32; i++) 
     heights[i] = (heights[i] + spectrum[0][i]) / 2;
@@ -126,7 +126,7 @@
 
   curloudness = (curloudness + 1)%200;
 
-  SDL_mutexV(mutex);
+  SDL_mutexV(sdlmutex);
 
 }
 
