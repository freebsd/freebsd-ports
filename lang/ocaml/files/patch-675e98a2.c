--- asmrun/startup.c.orig	2017-07-13 08:56:44 UTC
+++ asmrun/startup.c
@@ -44,8 +44,8 @@
 #endif
 
 extern int caml_parser_trace;
-CAMLexport header_t caml_atom_table[256];
 char * caml_code_area_start, * caml_code_area_end;
+struct ext_table caml_code_fragments_table;
 
 /* Initialize the atom table and the static data and code area limits. */
 
--- byterun/caml/intext.h.orig	2017-07-13 08:56:44 UTC
+++ byterun/caml/intext.h
@@ -196,7 +196,7 @@ struct code_fragment {
 
 CAMLextern struct code_fragment * caml_extern_find_code(char *addr);
 
-struct ext_table caml_code_fragments_table;
+extern struct ext_table caml_code_fragments_table;
 
 #endif /* CAML_INTERNALS */
 
--- byterun/caml/major_gc.h.orig	2017-07-13 08:56:44 UTC
+++ byterun/caml/major_gc.h
@@ -64,9 +64,9 @@ extern uintnat total_heap_size;
 extern char *caml_gc_sweep_hp;
 
 extern int caml_major_window;
-double caml_major_ring[Max_major_window];
-int caml_major_ring_index;
-double caml_major_work_credit;
+extern double caml_major_ring[Max_major_window];
+extern int caml_major_ring_index;
+extern double caml_major_work_credit;
 extern double caml_gc_clock;
 
 /* [caml_major_gc_hook] is called just between the end of the mark
--- byterun/fix_code.c.orig	2017-07-13 08:56:44 UTC
+++ byterun/fix_code.c
@@ -38,6 +38,7 @@
 code_t caml_start_code;
 asize_t caml_code_size;
 unsigned char * caml_saved_code;
+struct ext_table caml_code_fragments_table;
 
 /* Read the main bytecode block from a file */
 
