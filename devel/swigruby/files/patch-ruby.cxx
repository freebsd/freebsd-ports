--- ruby.cxx.orig	Thu May 25 01:18:29 2000
+++ ruby.cxx	Fri Nov  8 03:05:43 2002
@@ -840,3 +840,3 @@
 // ---------------------------------------------------------------------
-char *RUBY::ruby_typemap_lookup(char *op, DataType *type, char *pname, char *source, char *target, WrapperFunction *f = 0) {
+char *RUBY::ruby_typemap_lookup(char *op, DataType *type, char *pname, char *source, char *target, WrapperFunction *f) {
   static String s;
@@ -903,3 +903,3 @@
 // ---------------------------------------------------------------------
-char *RUBY::to_VALUE(DataType *type, char *value, int raw = 0) {
+char *RUBY::to_VALUE(DataType *type, char *value, int raw) {
   static String str;
