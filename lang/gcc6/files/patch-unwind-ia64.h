2012-12-17  Gerald Pfeifer  <gerald@pfeifer.com>
            Anton Shterenlikht  <mexas@bristol.ac.uk>

       PR target/45650
       * config/ia64/unwind-ia64.h: Do not mark _Unwind_FindTableEntry
       hidden on FreeBSD.

--- UTC
Index: libgcc/config/ia64/unwind-ia64.h
===================================================================
--- libgcc/config/ia64/unwind-ia64.h
+++ libgcc/config/ia64/unwind-ia64.h	(working copy)
@@ -49,4 +49,7 @@
 extern struct unw_table_entry *
 _Unwind_FindTableEntry (void *pc, unw_word *segment_base,
 			unw_word *gp, struct unw_table_entry *ent)
-			__attribute__ ((__visibility__ ("hidden")));
+#ifndef __FreeBSD__
+			__attribute__ ((__visibility__ ("hidden")))
+#endif
+			;
