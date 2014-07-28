--- rblocale.c.orig	2000-04-14 06:20:58.000000000 +0200
+++ rblocale.c	2013-06-21 12:52:36.000000000 +0200
@@ -27,10 +27,20 @@
 {
     char *ret;
 
-    ret = setlocale(NUM2INT(category), locale == Qnil ? "" : STR2CSTR(locale));
+    ret = setlocale(NUM2INT(category), locale == Qnil ? "" : StringValuePtr(locale));
     return ret == NULL ? Qnil : rb_str_new2(ret);
 }
 
+VALUE
+locale_get( self, category )
+	VALUE self, category;
+{
+	char  *ret;
+
+	ret = setlocale(NUM2INT(category), NULL );
+	return ret == NULL ? Qnil :  rb_str_new2(ret);
+}
+
 void Init_locale()
 {
     char *curr_locale;
@@ -44,6 +54,7 @@
     }
 
     rb_define_module_function(mLocale, "set", locale_set, 2);
+    rb_define_module_function(mLocale, "get", locale_get, 1);
 
     rb_define_const(mLocale, "ALL", INT2FIX(LC_ALL));
     rb_define_const(mLocale, "COLLATE", INT2FIX(LC_COLLATE));
