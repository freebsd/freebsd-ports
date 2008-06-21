--- intern.h.orig	2008-06-21 12:49:23.000000000 +0400
+++ intern.h	2008-06-21 12:49:29.000000000 +0400
@@ -400,6 +400,7 @@
 void ruby_default_signal _((int));
 /* sprintf.c */
 VALUE rb_f_sprintf _((int, VALUE*));
+VALUE rb_str_format _((int, VALUE*, VALUE));
 /* string.c */
 VALUE rb_str_new _((const char*, long));
 VALUE rb_str_new2 _((const char*));
