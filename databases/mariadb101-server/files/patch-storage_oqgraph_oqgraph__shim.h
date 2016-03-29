Patch to allow build with clang from Don Lewis
https://jira.mariadb.org/projects/MDEV/issues/MDEV-8051

--- storage/oqgraph/oqgraph_shim.h.orig	2016-01-28 12:12:55 UTC
+++ storage/oqgraph/oqgraph_shim.h
@@ -254,7 +254,7 @@ namespace boost
     typedef no_property type;
   };
 
-#if BOOST_VERSION >= 104601
+#if BOOST_VERSION >= 104601 && BOOST_VERSION < 104900
   template <>
   struct graph_bundle_type<oqgraph3::graph>
   {
@@ -274,6 +274,33 @@ namespace boost
   };
 #endif
 
+  template<>
+  struct property_map<oqgraph3::graph, edge_weight_t>
+  {
+    typedef void type;
+    typedef oqgraph3::edge_weight_property_map const_type;
+  };
+
+  template<>
+  struct property_map<oqgraph3::graph, vertex_index_t>
+  {
+    typedef void type;
+    typedef oqgraph3::vertex_index_property_map const_type;
+  };
+
+  template<>
+  struct property_map<oqgraph3::graph, edge_index_t>
+  {
+    typedef void type;
+    typedef oqgraph3::edge_index_property_map const_type;
+  };
+
+}
+
+namespace oqgraph3
+{
+  using namespace boost;
+
   inline graph_traits<oqgraph3::graph>::vertex_descriptor
   source(
       const graph_traits<oqgraph3::graph>::edge_descriptor& e,
@@ -401,27 +428,6 @@ namespace boost
     return count;
   }
 
-  template<>
-  struct property_map<oqgraph3::graph, edge_weight_t>
-  {
-    typedef void type;
-    typedef oqgraph3::edge_weight_property_map const_type;
-  };
-
-  template<>
-  struct property_map<oqgraph3::graph, vertex_index_t>
-  {
-    typedef void type;
-    typedef oqgraph3::vertex_index_property_map const_type;
-  };
-
-  template<>
-  struct property_map<oqgraph3::graph, edge_index_t>
-  {
-    typedef void type;
-    typedef oqgraph3::edge_index_property_map const_type;
-  };
-
   inline property_map<
       oqgraph3::graph,
       edge_weight_t>::const_type::reference
