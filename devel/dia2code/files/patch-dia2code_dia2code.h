--- dia2code/dia2code.h.orig	2020-08-28 18:44:14 UTC
+++ dia2code/dia2code.h
@@ -305,8 +305,8 @@ param_list * d2c_parameter_set(char *name, char *value
 char * d2c_parameter_value(char *name);
 param_list *d2c_parameter_find(char *name);
 
-int indent_count;
-int indent_open_brace_on_newline;
-int generate_backup;
+extern int indent_count;
+extern int indent_open_brace_on_newline;
+extern int generate_backup;
 
 #endif
