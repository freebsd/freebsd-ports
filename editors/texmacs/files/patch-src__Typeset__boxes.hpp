--- ./src/Typeset/boxes.hpp.orig	2014-08-28 13:13:20.617755990 -0400
+++ ./src/Typeset/boxes.hpp	2014-08-28 13:13:35.051223990 -0400
@@ -255,7 +255,7 @@
   friend class  phrase_box_rep;
   friend class  remember_box_rep;
   friend class  effect_box_rep;
-  friend void make_eps (url dest, box b, int dpi= 600);
+  friend void make_eps (url dest, box b, int dpi);
 };
 ABSTRACT_NULL_CODE(box);
 
