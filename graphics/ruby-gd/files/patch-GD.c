--- GD.c.orig	Tue Feb  6 15:47:42 2001
+++ GD.c	Mon Feb 12 19:39:15 2001
@@ -1200,7 +1200,7 @@
     Check_Type(fontname, T_STRING);
     Check_Type(string, T_STRING);
 
-    msg = gdImageStringTTF(NULL,
+    msg = gdImageStringFT(NULL,
                            &brect[0],
                            NUM2INT(fgcolor),
                            RSTRING(fontname)->ptr,
@@ -1232,7 +1232,7 @@
     Check_Type(string, T_STRING);
 
     Data_Get_Struct(img, gdImage, im);
-    msg = gdImageStringTTF(im,
+    msg = gdImageStringFT(im,
                            &brect[0],
                            NUM2INT(fgcolor),
                            RSTRING(fontname)->ptr,
@@ -1971,7 +1971,9 @@
 #endif    
 
 #ifdef HAVE_GDIMAGESTRINGFT
+    rb_define_singleton_method(cImage, "stringTTF", img_s_string_ft, 7);
     rb_define_singleton_method(cImage, "stringFT", img_s_string_ft, 7);
+    rb_define_method(cImage, "stringTTF", img_string_ft, 7);
     rb_define_method(cImage, "stringFT", img_string_ft, 7);
 #endif    
 
