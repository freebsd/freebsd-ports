--- runtime/startup_nat.c.orig	2019-08-05 17:32:44 UTC
+++ runtime/startup_nat.c
@@ -44,7 +44,6 @@ extern int caml_parser_trace;
 #endif
 
 extern int caml_parser_trace;
-CAMLexport header_t caml_atom_table[256];
 char * caml_code_area_start, * caml_code_area_end;
 struct ext_table caml_code_fragments_table;
 
