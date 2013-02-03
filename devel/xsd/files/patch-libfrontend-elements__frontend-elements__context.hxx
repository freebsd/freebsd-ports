C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libfrontend-elements/frontend-elements/context.hxx~	2012-08-10 23:30:34.000000000 -0300
+++ libfrontend-elements/frontend-elements/context.hxx	2012-08-10 23:30:49.000000000 -0300
@@ -122,7 +122,7 @@
       if (i == map_.end ())
         throw NoEntry ();
 
-      map_.erase (i);
+      map_.erase (i.base ());
     }
 
   private:
