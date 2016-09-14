--- main.cpp.orig	2016-08-13 02:07:57 UTC
+++ main.cpp
@@ -27,15 +27,18 @@
 #include <fstream>
 #include <iostream>
 #include <sstream>
+#include <unistd.h> // for usleep()
 
 #include <sys/time.h>
 
-#ifndef WIN32
-    #include <endian.h>
-#else
+#if defined(WIN32)
     typedef unsigned int uint;
     #include <windows.h>
     #include <GL/glext.h>
+#elif defined(__FreeBSD__)
+    #include <sys/endian.h>
+#else
+    #include <endian.h>
 #endif
 
 
@@ -348,6 +351,7 @@ bool classBullets::col(vector<vert> targ
       }
     }
   }
+  return false;
 }
 
 void classBullets::shoot(entity owner, gPs velocity)
@@ -1826,9 +1830,9 @@ int main(int argc, char **argv)
 
   GLfloat scale;
 
-  readEnt("ship.txt", gameInfo.shipStaticVerts);
-  readEnt("base.txt", gameInfo.baseStaticVerts);
-  readEnt("enemy.txt", gameInfo.enemyStaticVerts);
+  readEnt(DATADIR "ship.txt", gameInfo.shipStaticVerts);
+  readEnt(DATADIR "base.txt", gameInfo.baseStaticVerts);
+  readEnt(DATADIR "enemy.txt", gameInfo.enemyStaticVerts);
 
   //Enter Main loop
   while(gameState != GameStateQuit)
@@ -1958,7 +1962,7 @@ int main(int argc, char **argv)
               break;
 
             case SDLK_d:
-              saveMap(polys, ents, "verts.txt");
+              saveMap(polys, ents, DATADIR "verts.txt");
             break;
 
             case SDLK_s:
