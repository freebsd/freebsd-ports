--- contrib/MeshOptimizer/VertexCoord.cpp.orig	2024-03-29 22:06:54 UTC
+++ contrib/MeshOptimizer/VertexCoord.cpp
@@ -76,12 +76,12 @@ void VertexCoordParent::gXyz2gUvw(const SPoint3 &uvw, 
     gUvw[0] = gXyz.x() * der.x() + gXyz.y() * der.y() + gXyz.z() * der.z();
   }
   else {
-    Pair<SVector3, SVector3> der =
+    std::pair<SVector3, SVector3> der =
       static_cast<GFace *>(ge)->firstDer(SPoint2(uvw[0], uvw[1]));
-    gUvw[0] = gXyz.x() * der.first().x() + gXyz.y() * der.first().y() +
-              gXyz.z() * der.first().z();
-    gUvw[1] = gXyz.x() * der.second().x() + gXyz.y() * der.second().y() +
-              gXyz.z() * der.second().z();
+    gUvw[0] = gXyz.x() * der.first.x() + gXyz.y() * der.first.y() +
+              gXyz.z() * der.first.z();
+    gUvw[1] = gXyz.x() * der.second.x() + gXyz.y() * der.second.y() +
+              gXyz.z() * der.second.z();
   }
 }
 
@@ -101,15 +101,15 @@ void VertexCoordParent::gXyz2gUvw(const SPoint3 &uvw,
     }
   }
   else {
-    Pair<SVector3, SVector3> der =
+    std::pair<SVector3, SVector3> der =
       static_cast<GFace *>(ge)->firstDer(SPoint2(uvw[0], uvw[1]));
     auto itUvw = gUvw.begin();
     for(auto itXyz = gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
-      (*itUvw)[0] = itXyz->x() * der.first().x() +
-                    itXyz->y() * der.first().y() + itXyz->z() * der.first().z();
-      (*itUvw)[1] = itXyz->x() * der.second().x() +
-                    itXyz->y() * der.second().y() +
-                    itXyz->z() * der.second().z();
+      (*itUvw)[0] = itXyz->x() * der.first.x() +
+                    itXyz->y() * der.first.y() + itXyz->z() * der.first.z();
+      (*itUvw)[1] = itXyz->x() * der.second.x() +
+                    itXyz->y() * der.second.y() +
+                    itXyz->z() * der.second.z();
       itUvw++;
     }
   }
