2010-09-12  Gerald Pfeifer  <gerald@pfeifer.com>

       PR target/45650
       * config/ia64/unwind-ia64.h: Do not mark _Unwind_FindTableEntry
       hidden on FreeBSD.

Index: gcc/config/ia64/unwind-ia64.h
===================================================================
--- gcc/config/ia64/unwind-ia64.h	(revision 164211)
+++ gcc/config/ia64/unwind-ia64.h	(working copy)
@@ -40,4 +40,7 @@
 extern struct unw_table_entry *
 _Unwind_FindTableEntry (void *pc, unsigned long *segment_base,
 			unsigned long *gp, struct unw_table_entry *ent)
-			__attribute__ ((__visibility__ ("hidden")));
+#ifndef __FreeBSD__
+			__attribute__ ((__visibility__ ("hidden")))
+#endif
+                        ;
