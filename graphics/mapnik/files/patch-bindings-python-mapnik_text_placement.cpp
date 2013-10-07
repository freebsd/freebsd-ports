--- bindings/python/mapnik_text_placement.cpp.orig	2013-09-14 06:44:28.000000000 +0400
+++ bindings/python/mapnik_text_placement.cpp	2013-09-14 06:46:57.000000000 +0400
@@ -194,7 +194,11 @@
     ListNodeWrap(object l) : formatting::list_node(), wrapper<formatting::list_node>()
     {
         stl_input_iterator<formatting::node_ptr> begin(l), end;
-        children_.insert(children_.end(), begin, end);
+        while (begin != end)
+        {
+           children_.push_back(*begin);
+           ++begin;
+        }
     }
 
     /* TODO: Add constructor taking variable number of arguments.
