C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libxsd-frontend/xsd-frontend/semantic-graph/elements.hxx~	2010-04-27 16:31:24.000000000 -0300
+++ libxsd-frontend/xsd-frontend/semantic-graph/elements.hxx	2012-08-10 23:18:42.000000000 -0300
@@ -553,7 +553,7 @@
         assert (i != iterator_map_.end ());
 
         names_.erase (i->second);
-        iterator_map_.erase (i);
+        iterator_map_.erase (i.base ());
 
         NamesMap::Iterator j (names_map_.find (e.name ()));
 
@@ -1143,7 +1143,7 @@
       Void
       add_edge_right (Arguments& a, ArgumentedIterator const& pos)
       {
-        argumented_.insert (pos.base (), &a);
+        argumented_.insert (pos.base ().base (), &a);
       }
 
     private:
