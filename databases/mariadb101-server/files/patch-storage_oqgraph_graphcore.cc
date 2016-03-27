Patch to allow build with clang from Don Lewis
https://jira.mariadb.org/projects/MDEV/issues/MDEV-8051

--- storage/oqgraph/graphcore.cc.orig	2016-01-28 12:12:55 UTC
+++ storage/oqgraph/graphcore.cc
@@ -485,7 +485,7 @@ namespace open_query
   optional<Vertex>
   oqgraph_share::find_vertex(VertexID id) const
   {
-    return ::boost::find_vertex(id, g);
+    return oqgraph3::find_vertex(id, g);
   }
 
 #if 0
