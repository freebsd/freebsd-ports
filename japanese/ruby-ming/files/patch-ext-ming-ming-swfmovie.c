--- ext/ming/ming/swfmovie.c.orig	2003-09-28 13:22:16.000000000 +0900
+++ ext/ming/ming/swfmovie.c	2014-01-29 17:11:21.000000000 +0900
@@ -108,7 +108,7 @@
   int count;
 
   Data_Get_Struct(self, struct RSWFMovie, m);
-  count = SWFMovie_save(m->this, STR2CSTR(s));
+  count = SWFMovie_save(m->this, StringValuePtr(s));
 
   return INT2NUM(count);
 }
@@ -226,7 +226,7 @@
   struct RSWFMovie *m;
 
   Data_Get_Struct(self, struct RSWFMovie, m);
-  SWFMovie_labelFrame(m->this, STR2CSTR(label));
+  SWFMovie_labelFrame(m->this, StringValuePtr(label));
 
   return self;
 }
@@ -248,7 +248,7 @@
 	 VALUE self, n;
 {
   struct RSWFMovie *m;
-  char *name = STR2CSTR(n);
+  char *name = StringValuePtr(n);
   FILE *fp;
   VALUE path = rb_cv_get(rb_cSWFMovie, "@@mp3_path");
 #ifdef SUPPORT_PCM
@@ -286,7 +286,7 @@
   Data_Get_Struct(block, struct RSWFBlock, b);
 
   regist_references(m->table, n);
-  SWFMovie_addExport(m->this, b->this, STR2CSTR(n));
+  SWFMovie_addExport(m->this, b->this, StringValuePtr(n));
   
   return self;
 }
@@ -331,7 +331,7 @@
 {
   struct RSWFMovie *m;
   struct RSWFDisplayItem *i;
-  char *name = STR2CSTR(n);
+  char *name = StringValuePtr(n);
   FILE *fp;
   VALUE obj, path = rb_cv_get(rb_cSWFMovie, "@@mp3_path");
   SWFSound sound;
