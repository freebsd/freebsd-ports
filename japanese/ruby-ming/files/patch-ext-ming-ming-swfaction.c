--- ext/ming/ming/swfaction.c.orig	2003-09-28 13:30:00.000000000 +0900
+++ ext/ming/ming/swfaction.c	2014-01-29 17:11:21.000000000 +0900
@@ -36,7 +36,7 @@
 rb_SWFAction_s_new(self, s)
 	 VALUE self, s;
 {
-  char *script = STR2CSTR(s);
+  char *script = StringValuePtr(s);
   struct RSWFAction *a = ALLOC(struct RSWFAction);
   VALUE obj;
 
