Fix clang error due to an ambiguity in the name lookup (Node is also defined by
libcult).
--- libxsd-frontend/xsd-frontend/semantic-graph/schema.hxx~	2012-08-06 23:55:53.000000000 -0300
+++ libxsd-frontend/xsd-frontend/semantic-graph/schema.hxx	2012-08-06 23:56:33.000000000 -0300
@@ -241,7 +241,7 @@
       friend class Bits::Graph<SemanticGraph::Node, Edge>;
 
       using Scope::add_edge_left;
-      using Node::add_edge_right;
+      using SemanticGraph::Node::add_edge_right;
 
       Void
       add_edge_left (Uses& e)
