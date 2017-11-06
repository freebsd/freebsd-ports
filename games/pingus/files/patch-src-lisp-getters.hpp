--- src/lisp/getters.hpp.orig	2011-12-24 21:46:47 UTC
+++ src/lisp/getters.hpp
@@ -30,7 +30,7 @@ static inline bool property_get(const Li
   if(lisp->get_list_size() != 2)
     return false;
   
-  const Lisp* el = lisp->get_list_elem(1);
+  const Lisp* el = lisp->get_list_elem(1).get();
   return get(el, val);
 }
 
