--- asmrun/startup.c.orig	2017-07-13 08:56:44 UTC
+++ asmrun/startup.c
@@ -44,7 +44,6 @@
 #endif
 
 extern int caml_parser_trace;
-CAMLexport header_t caml_atom_table[256];
 char * caml_code_area_start, * caml_code_area_end;
 struct ext_table caml_code_fragments_table;
 
