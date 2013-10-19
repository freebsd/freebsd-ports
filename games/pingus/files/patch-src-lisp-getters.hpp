--- src/lisp/getters.hpp.orig	2007-08-17 20:20:09.000000000 +0400
+++ src/lisp/getters.hpp	2013-08-09 13:42:19.551761882 +0400
@@ -30,7 +30,7 @@
   if(lisp->get_list_size() != 2)
     return false;
   
-  const Lisp* el = lisp->get_list_elem(1);
+  const Lisp* el = lisp->get_list_elem(1).get();
   return get(el, val);
 }
 
