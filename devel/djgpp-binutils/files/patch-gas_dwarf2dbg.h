--- gas/dwarf2dbg.h.orig	2020-08-28 19:16:43 UTC
+++ gas/dwarf2dbg.h
@@ -78,7 +78,7 @@ extern void dwarf2_emit_label (symbolS *);
 /* True when we're supposed to set the basic block mark whenever a label
    is seen.  Unless the target is doing Something Weird, just call 
    dwarf2_emit_label.  */
-bfd_boolean dwarf2_loc_mark_labels;
+extern bfd_boolean dwarf2_loc_mark_labels;
 
 extern void dwarf2_finish (void);
 
