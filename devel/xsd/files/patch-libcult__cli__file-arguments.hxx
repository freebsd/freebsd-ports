C++11 build fix.

Operations such as insert() and erase() in sequential vectors such as
std::vector now take a const_iterator instead of an iterator in C++11, and
implicitly converting a Container::Vector::Iterator into a const_iterator
fails.  We thus resort to just passing the wrapped std::$CONTAINER::iterator
which can then be converted as expected.
--- libcult/cult/cli/file-arguments.hxx~	2012-08-10 23:14:36.000000000 -0300
+++ libcult/cult/cli/file-arguments.hxx	2012-08-10 23:12:30.000000000 -0300
@@ -47,7 +47,7 @@
         if (i >= size ())
           throw Bounds ();
 
-        args_.erase (args_.begin () + i);
+        args_.erase (args_.begin ().base () + i);
       }
 
     private:
