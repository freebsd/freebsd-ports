--- gdchart.c.orig	Mon Nov 27 00:47:58 2000
+++ gdchart.c	Mon Jul 16 17:23:54 2001
@@ -16,6 +16,11 @@
 #include "rubyio.h"
 
 VALUE
+mgdc_get_image_type(VALUE obj) { return INT2FIX(GDC_image_type); }
+VALUE
+mgdc_set_image_type(VALUE obj, VALUE arg) { GDC_image_type = FIX2INT(arg); }
+
+VALUE
 mgdc_get_ytitle(VALUE obj) { return rb_str_new2(GDC_ytitle); }
 VALUE
 mgdc_set_ytitle(VALUE obj, VALUE arg) { GDC_ytitle = STR2CSTR(arg); }
@@ -443,6 +448,8 @@
 #endif
     rb_define_module_function(mGDChart, "out_graph", mgdc_out_graph, 8);
 
+    rb_define_module_function(mGDChart, "image_type", mgdc_get_image_type, 0);
+    rb_define_module_function(mGDChart, "image_type=", mgdc_set_image_type, 1);    
     rb_define_module_function(mGDChart, "ytitle", mgdc_get_ytitle, 0);
     rb_define_module_function(mGDChart, "ytitle=", mgdc_set_ytitle, 1);
     rb_define_module_function(mGDChart, "xtitle", mgdc_get_xtitle, 0);
