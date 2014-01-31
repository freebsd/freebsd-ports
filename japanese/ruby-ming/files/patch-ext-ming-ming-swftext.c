--- ext/ming/ming/swftext.c.orig	2003-09-28 13:30:34.000000000 +0900
+++ ext/ming/ming/swftext.c	2014-01-29 17:11:21.000000000 +0900
@@ -143,7 +143,7 @@
 
   Data_Get_Struct(self, struct RSWFText, p);
 
-  SWFText_addString(p->this, STR2CSTR(s), NULL);
+  SWFText_addString(p->this, StringValuePtr(s), NULL);
   return self;
 }
 
@@ -154,7 +154,7 @@
   struct RSWFText *p;
 
   Data_Get_Struct(self, struct RSWFText, p);
-  return rb_float_new(SWFText_getStringWidth(p->this, STR2CSTR(s)));
+  return rb_float_new(SWFText_getStringWidth(p->this, StringValuePtr(s)));
 }
 
 static VALUE
