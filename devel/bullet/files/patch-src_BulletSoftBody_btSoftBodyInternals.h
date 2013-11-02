--- src/BulletSoftBody/btSoftBodyInternals.h.orig	2009-08-31 04:35:06.000000000 +0000
+++ src/BulletSoftBody/btSoftBodyInternals.h
@@ -25,6 +25,7 @@ subject to the following restrictions:
 #include "BulletCollision/CollisionDispatch/btCollisionDispatcher.h"
 #include "BulletCollision/CollisionShapes/btConvexInternalShape.h"
 #include "BulletCollision/NarrowPhaseCollision/btGjkEpa2.h"
+#include <string.h>
 
 //
 // btSymMatrix
@@ -172,8 +173,7 @@ public:
 template <typename T>
 static inline void			ZeroInitialize(T& value)
 {
-	static const T	zerodummy;
-	value=zerodummy;
+	memset(&value, 0, sizeof(T));
 }
 //
 template <typename T>
