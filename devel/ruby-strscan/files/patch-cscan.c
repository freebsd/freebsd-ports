--- ext/cscan/cscan.c.orig	Sat Apr  7 14:47:31 2001
+++ ext/cscan/cscan.c	Mon Sep 17 13:28:33 2001
@@ -595,8 +595,7 @@
         ScanError = rb_const_get(rb_cObject, id_scanerr);
     }
     else {
-        ScanError = rb_define_class("ScanError", rb_eStandardError);
-        rb_define_const(rb_cObject, "ScanError", ScanError);
+        ScanError = rb_define_class_id(id_scanerr, rb_eStandardError);
     }
 
     StringScanner = rb_define_class("StringScanner_C", rb_cObject);
