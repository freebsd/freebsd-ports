C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- xsd/xsd/cxx/parser/state-processor.cxx~	2010-04-28 03:58:09.000000000 -0300
+++ xsd/xsd/cxx/parser/state-processor.cxx	2012-08-10 23:25:49.000000000 -0300
@@ -154,7 +154,7 @@
               if (++depth > depth_) // One for this compositor.
                 depth_ = depth;
 
-              prefixes_.insert (prefixes_.end (),
+              prefixes_.insert (prefixes_.end ().base (),
                                 t.prefixes_.begin ().base (),
                                 t.prefixes_.end ().base ());
 
@@ -229,7 +229,7 @@
 
               if (prefix)
               {
-                prefixes_.insert (prefixes_.end (),
+                prefixes_.insert (prefixes_.end ().base (),
                                   t.prefixes_.begin ().base (),
                                   t.prefixes_.end ().base ());
 
