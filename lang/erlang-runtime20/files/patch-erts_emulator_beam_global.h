--- erts/emulator/beam/global.h.orig	2020-08-28 21:32:51 UTC
+++ erts/emulator/beam/global.h
@@ -959,8 +959,8 @@ void erts_update_ranges(BeamInstr* code, Uint size);
 void erts_remove_from_ranges(BeamInstr* code);
 UWord erts_ranges_sz(void);
 void erts_lookup_function_info(FunctionInfo* fi, BeamInstr* pc, int full_info);
-ErtsLiteralArea** erts_dump_lit_areas;
-Uint erts_dump_num_lit_areas;
+extern ErtsLiteralArea** erts_dump_lit_areas;
+extern Uint erts_dump_num_lit_areas;
 
 /* break.c */
 void init_break_handler(void);
