--- final.c.orig	Sun Nov 26 10:50:00 1995
+++ final.c	Mon Mar 20 13:29:11 2000
@@ -345,6 +345,8 @@
       /* zero word */
       assemble_integer (const0_rtx, UNITS_PER_WORD, 1);
 
+      fprintf(asm_out_file,".stabs \"bbset\", 25, 0, 0, LPBX0\n");
+
       /* address of filename */
       ASM_GENERATE_INTERNAL_LABEL (name, "LPBX", 1);
       assemble_integer (gen_rtx (SYMBOL_REF, Pmode, name), UNITS_PER_WORD, 1);
@@ -914,6 +916,9 @@
     leaf_renumber_regs (first);
 #endif
 
+  if (profile_block_flag)
+    add_bb (file);
+
   /* The Sun386i and perhaps other machines don't work right
      if the profiling code comes after the prologue.  */
 #ifdef PROFILE_BEFORE_PROLOGUE
@@ -971,14 +976,18 @@
 profile_function (file)
      FILE *file;
 {
+#ifndef NO_PROFILE_DATA
   int align = MIN (BIGGEST_ALIGNMENT, POINTER_SIZE);
+#endif /* not NO_PROFILE_DATA */
   int sval = current_function_returns_struct;
   int cxt = current_function_needs_context;
 
+#ifndef NO_PROFILE_DATA
   data_section ();
   ASM_OUTPUT_ALIGN (file, floor_log2 (align / BITS_PER_UNIT));
   ASM_OUTPUT_INTERNAL_LABEL (file, "LP", profile_label_no);
   assemble_integer (const0_rtx, POINTER_SIZE / BITS_PER_UNIT, 1);
+#endif /* not NO_PROFILE_DATA */
 
   text_section ();
 
@@ -1066,6 +1075,9 @@
   FUNCTION_EPILOGUE (file, get_frame_size ());
 #endif
 
+  if (profile_block_flag)
+    add_bb (file);
+
 #ifdef SDB_DEBUGGING_INFO
   if (write_symbols == SDB_DEBUG)
     sdbout_end_epilogue ();
@@ -1487,6 +1499,9 @@
       if (prescan > 0)
 	break;
       new_block = 1;
+#ifdef FINAL_PRESCAN_INSN
+      FINAL_PRESCAN_INSN (insn, NULL_RTX, 0);
+#endif
 #ifdef SDB_DEBUGGING_INFO
       if (write_symbols == SDB_DEBUG && LABEL_NAME (insn))
 	sdbout_label (insn);
