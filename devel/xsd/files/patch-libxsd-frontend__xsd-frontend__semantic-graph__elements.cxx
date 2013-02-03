C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libxsd-frontend/xsd-frontend/semantic-graph/elements.cxx~	2012-06-03 06:02:29.000000000 -0300
+++ libxsd-frontend/xsd-frontend/semantic-graph/elements.cxx	2012-08-10 23:45:53.000000000 -0300
@@ -43,7 +43,7 @@
         std::find (argumented_.begin (), argumented_.end (), &a));
 
       assert (i != argumented_.end ());
-      argumented_.erase (i);
+      argumented_.erase (i.base ());
     }
 
     namespace RTTI = Cult::RTTI;
