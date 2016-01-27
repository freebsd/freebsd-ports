--- components/resource/bulletshape.cpp.orig	2016-01-12 16:11:28 UTC
+++ components/resource/bulletshape.cpp
@@ -1,6 +1,7 @@
 #include "bulletshape.hpp"
 
 #include <stdexcept>
+#include <string>
 
 #include <BulletCollision/CollisionShapes/btBoxShape.h>
 #include <BulletCollision/CollisionShapes/btTriangleMesh.h>
