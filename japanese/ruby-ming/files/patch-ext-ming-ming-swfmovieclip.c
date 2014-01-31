--- ext/ming/ming/swfmovieclip.c.orig	2003-09-28 12:33:14.000000000 +0900
+++ ext/ming/ming/swfmovieclip.c	2014-01-29 17:11:21.000000000 +0900
@@ -135,7 +135,7 @@
 
   Data_Get_Struct(self, struct RSWFMovieClip, m);
 
-  SWFMovieClip_labelFrame(m->this, STR2CSTR(s));
+  SWFMovieClip_labelFrame(m->this, StringValuePtr(s));
 
   return self;
 }
@@ -158,7 +158,7 @@
 	 VALUE self, n, r;
 {
   struct RSWFMovie *m;
-  char *name = STR2CSTR(n);
+  char *name = StringValuePtr(n);
   FILE *fp;
   VALUE path = rb_cv_get(rb_cSWFMovie, "@@mp3_path");
 #ifdef SUPPORT_PCM
