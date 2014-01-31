--- ext/ming/ming/swffont.c.orig	2003-09-28 12:51:28.000000000 +0900
+++ ext/ming/ming/swffont.c	2014-01-29 17:11:21.000000000 +0900
@@ -44,16 +44,16 @@
 	 VALUE self, n;
 {
   struct RSWFFont *f = ALLOC(struct RSWFFont);
-  char *name = STR2CSTR(n), *ext;
+  char *name = StringValuePtr(n), *ext;
   size_t len;
   FILE *fp;
   VALUE obj;
 
   VALUE path = rb_cv_get(rb_cSWFFont, "@@font_path");
-  len = RSTRING(n)->len;
+  len = RSTRING_LEN(n);
 
   if(len > 4) {
-    ext = &name[RSTRING(n)->len - 4];
+    ext = &name[RSTRING_LEN(n) - 4];
 
     if (strncmp_ignore_case(ext, ".fdb", 4) == 0) {
       fp = search_file(path, name, "rb");
@@ -92,7 +92,7 @@
 
   Data_Get_Struct(self, struct RSWFFont, f);
 
-  return rb_float_new(SWFFont_getStringWidth(f->this, STR2CSTR(s)));
+  return rb_float_new(SWFFont_getStringWidth(f->this, StringValuePtr(s)));
 }
 
 static VALUE
