--- include/tdep-x86_64/libunwind_i.h.orig	2021-11-26 16:58:55 UTC
+++ include/tdep-x86_64/libunwind_i.h
@@ -288,9 +288,9 @@ extern void tdep_reuse_frame (struct dwarf_cursor *c,
 extern int tdep_cache_frame (struct dwarf_cursor *c);
 extern void tdep_reuse_frame (struct dwarf_cursor *c,
                               int frame);
+#endif
 extern void tdep_stash_frame (struct dwarf_cursor *c,
                               struct dwarf_reg_state *rs);
-#endif
 
 extern int tdep_getcontext_trace (unw_tdep_context_t *);
 extern int tdep_trace (unw_cursor_t *cursor, void **addresses, int *n);
