--- src/core/calcnode.cpp.orig	2018-05-10 18:06:35 UTC
+++ src/core/calcnode.cpp
@@ -5932,7 +5932,7 @@ void    _TheTree::TreePSRecurse (node<no
         res << "0 0 0 setrgbcolor\n";
     }
 
-    if (iterator->is_root() == nil && layout == 1) {
+    if (!iterator->is_root() && layout == 1) {
         res <<  (_String (-iterator->in_object.h) & ' ' & _String (-iterator->in_object.v) & " translate\n");
     }
 }
