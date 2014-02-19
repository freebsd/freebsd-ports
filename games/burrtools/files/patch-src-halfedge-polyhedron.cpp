--- src/halfedge/polyhedron.cpp.orig	2011-07-23 21:04:15.000000000 +0400
+++ src/halfedge/polyhedron.cpp	2014-02-19 09:19:56.242568734 +0400
@@ -206,12 +206,12 @@
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
