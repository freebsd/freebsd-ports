C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libbackend-elements/backend-elements/indentation/cxx.hxx~	2010-01-01 09:17:20.000000000 -0200
+++ libbackend-elements/backend-elements/indentation/cxx.hxx	2012-08-10 23:36:46.000000000 -0300
@@ -580,7 +580,7 @@
                   if (*i == '}')
                   {
                     ++i;
-                    hold_.erase (i);
+                    hold_.erase (i.base ());
                     break;
                   }
                 }
