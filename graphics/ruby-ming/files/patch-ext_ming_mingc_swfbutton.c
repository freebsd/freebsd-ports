--- ext/ming/mingc/swfbutton.c.orig	2011-08-08 14:03:05.000000000 +0000
+++ ext/ming/mingc/swfbutton.c	2011-08-08 14:04:58.000000000 +0000
@@ -49,10 +49,10 @@
 {
   if(TYPE(key) != T_STRING)
     rb_raise(rb_eMingError, "Argument must be a character on keyboard.");
-  if(RSTRING(key)->len != 1)
+  if(RSTRING_LEN(key) != 1)
         rb_raise(rb_eMingError, "Size of argument must be just 1.");
 
-  return INT2FIX(SWFBUTTON_KEYPRESS(RSTRING(key)->ptr[0]));
+  return INT2FIX(SWFBUTTON_KEYPRESS(RSTRING_PTR(key)[0]));
 }
 
 static VALUE
@@ -61,10 +61,10 @@
 {
   if(TYPE(key) != T_STRING)
     rb_raise(rb_eMingError, "Argument must be a character on keyboard.");
-  if(RSTRING(key)->len != 1)
+  if(RSTRING_LEN(key) != 1)
         rb_raise(rb_eMingError, "Size of argument must be just 1.");
 
-  return INT2FIX(SWFBUTTON_ONKEYPRESS(RSTRING(key)->ptr[0]));
+  return INT2FIX(SWFBUTTON_ONKEYPRESS(RSTRING_PTR(key)[0]));
 }
 
 static VALUE
