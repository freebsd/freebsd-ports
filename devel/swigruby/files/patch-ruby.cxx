--- ruby.cxx.orig	Wed May 24 19:18:29 2000
+++ ruby.cxx	Wed Aug 17 11:08:17 2005
@@ -24,7 +24,7 @@
 
 static char *extconf_rb = "\
 require 'mkmf'\n\
-
+\
 #%ext%_dir         = with_config('%ext%-dir')\n\
 #%ext%_include_dir = %ext%_dir + '/include' if %ext%_dir\n\
 #%ext%_include_dir = with_config('%ext%-include-dir', %ext%_include_dir)\n\
@@ -838,7 +838,7 @@
 //              target = a string containing the target value
 //              f      = a wrapper function object (optional)
 // ---------------------------------------------------------------------
-char *RUBY::ruby_typemap_lookup(char *op, DataType *type, char *pname, char *source, char *target, WrapperFunction *f = 0) {
+char *RUBY::ruby_typemap_lookup(char *op, DataType *type, char *pname, char *source, char *target, WrapperFunction *f) {
   static String s;
   char *tm;
   String target_replace = target;
@@ -901,7 +901,7 @@
 //              value = C value (as a string)
 //              raw = value is raw string (not quoted) ? 
 // ---------------------------------------------------------------------
-char *RUBY::to_VALUE(DataType *type, char *value, int raw = 0) {
+char *RUBY::to_VALUE(DataType *type, char *value, int raw) {
   static String str;
 
   str = "";
