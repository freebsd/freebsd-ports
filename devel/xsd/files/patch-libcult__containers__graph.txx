C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libcult/cult/containers/graph.txx~	2010-04-15 03:52:59.000000000 -0300
+++ libcult/cult/containers/graph.txx	2012-08-10 23:21:50.000000000 -0300
@@ -307,7 +307,7 @@
       edge.clear_right_node (r);
       edge.clear_left_node (l);
 
-      edges_.erase (i);
+      edges_.erase (i.base ());
     }
   }
 }
