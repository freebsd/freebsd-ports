--- src/halfedge/polyhedron.cpp.orig	2013-05-08 19:02:06 UTC
+++ src/halfedge/polyhedron.cpp
@@ -206,12 +206,12 @@ void Polyhedron::finalize(void)
     // add the edge, to make sure we don't process it again
     handeled.insert(idx);
 
-    map<pair<int,int>, HalfEdge*>::iterator cit = connections.find(idx);
+    multimap<pair<int,int>, HalfEdge*>::iterator cit = connections.find(idx);
     // now we have the very first halfedge conection our 2 vertices, first let's count how many there are
 
     int n = 0;
     {
-      map<pair<int,int>, HalfEdge*>::iterator cit2 = cit;
+      multimap<pair<int,int>, HalfEdge*>::iterator cit2 = cit;
       while (cit2->first == idx)
       {
         n++;
