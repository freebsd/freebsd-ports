--- src/Object.C	Mon May 10 13:41:22 1999
+++ src/Object.C	Sat Oct 26 00:40:49 2002
@@ -28,7 +28,7 @@
  */
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "Object.H"
 #include "World.H"
@@ -89,7 +89,7 @@
 
   do {
     //    if (yes)
-    //      cout << "Object::auto_position(): collide #" << yes << endl;
+    //      std::cout << "Object::auto_position(): collide #" << yes << std::endl;
     //    yes++;
     pos.x = rand() % world.x_dim;
     pos.y = rand() % world.y_dim;
