--- GD.c.orig	2001-05-30 16:14:17.000000000 +0200
+++ GD.c	2015-12-03 15:03:58.428323000 +0100
@@ -1191,7 +1191,7 @@
     Check_Type(fontname, T_STRING);
     Check_Type(string, T_STRING);
 
-    msg = gdImageStringTTF(NULL,
+    msg = gdImageStringFT(NULL,
                            &brect[0],
                            NUM2INT(fgcolor),
                            RSTRING(fontname)->ptr,
@@ -1223,7 +1223,7 @@
     Check_Type(string, T_STRING);
 
     Data_Get_Struct(img, gdImage, im);
-    msg = gdImageStringTTF(im,
+    msg = gdImageStringFT(im,
                            &brect[0],
                            NUM2INT(fgcolor),
                            RSTRING(fontname)->ptr,
@@ -1613,7 +1613,7 @@
 {
     VALUE self = rb_ary_new();
 
-    RBASIC(self)->klass = klass;
+    rb_obj_reveal(self, klass);
     return self;
 }
 
@@ -2508,7 +2508,9 @@
 #endif    
 
 #ifdef HAVE_GDIMAGESTRINGFT
+    rb_define_singleton_method(cImage, "stringTTF", img_s_string_ft, 7);
     rb_define_singleton_method(cImage, "stringFT", img_s_string_ft, 7);
+    rb_define_method(cImage, "stringTTF", img_string_ft, 7);
     rb_define_method(cImage, "stringFT", img_string_ft, 7);
 #endif    
 
