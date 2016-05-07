--- src/Object.C.orig	1999-05-10 03:41:22 UTC
+++ src/Object.C
@@ -28,7 +28,7 @@
  */
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "Object.H"
 #include "World.H"
@@ -89,7 +89,7 @@ void _Object::auto_position(Map& map)
 
   do {
     //    if (yes)
-    //      cout << "Object::auto_position(): collide #" << yes << endl;
+    //      std::cout << "Object::auto_position(): collide #" << yes << std::endl;
     //    yes++;
     pos.x = rand() % world.x_dim;
     pos.y = rand() % world.y_dim;
