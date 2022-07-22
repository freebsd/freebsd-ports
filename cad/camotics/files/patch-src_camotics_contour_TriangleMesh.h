--- src/camotics/contour/TriangleMesh.h.orig	2021-07-27 23:51:08 UTC
+++ src/camotics/contour/TriangleMesh.h
@@ -52,7 +52,7 @@ namespace CAMotics {
 
 
     struct VertexSort {
-      bool operator() (const Vertex *a, const Vertex *b) {return *a < *b;}
+      bool operator() (const Vertex *a, const Vertex *b) const {return *a < *b;}
     };
 
 
