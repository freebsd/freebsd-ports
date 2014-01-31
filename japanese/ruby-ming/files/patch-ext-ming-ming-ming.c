--- ext/ming/ming/ming.c.orig	2003-09-28 13:51:44.000000000 +0900
+++ ext/ming/ming/ming.c	2014-01-29 17:11:21.000000000 +0900
@@ -56,10 +56,10 @@
 {
   if(TYPE(c) != T_STRING)
 	rb_raise(rb_eMingError, "Argument must be a character on keyboard.");
-  if(RSTRING(c)->len != 1)
+  if(RSTRING_LEN(c) != 1)
 	rb_raise(rb_eMingError, "Size of argument must be just 1.");
   
-  return INT2FIX(SWFBUTTON_KEYPRESS(RSTRING(c)->ptr[0]));
+  return INT2FIX(SWFBUTTON_KEYPRESS(RSTRING_PTR(c)[0]));
 }
 
 static VALUE
@@ -68,10 +68,10 @@
 {
   if(TYPE(c) != T_STRING)
 	rb_raise(rb_eMingError, "Argument must be character on keyboard.");
-  if(RSTRING(c)->len != 1)
+  if(RSTRING_LEN(c) != 1)
 	rb_raise(rb_eMingError, "Size of argument must be just 1.");
 
-  return INT2FIX(SWFBUTTON_ONKEYPRESS(RSTRING(c)->ptr[0]));
+  return INT2FIX(SWFBUTTON_ONKEYPRESS(RSTRING_PTR(c)[0]));
 }
 
 void rb_Ming_raise(char *msg, ...)
