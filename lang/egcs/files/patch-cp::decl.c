--- gcc/cp/decl.c.orig	1999/08/26 09:28:46	1.1.1.2
+++ gcc/cp/decl.c	1999/09/19 10:57:59	1.3
@@ -19,7 +19,9 @@
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
+/* $from_FreeBSD: src/contrib/gcc/cp/decl.c,v 1.3 1999/09/19 10:57:59 obrien Exp $ */
 
+
 /* Process declarations and symbol lookup for C front end.
    Also constructs types; the standard scalar types at initialization,
    and structure, union, array and enum types when they are declared.  */
@@ -1493,7 +1495,7 @@
   tree t;
   int i = 0, len;
   fprintf (stderr, " blocks=");
-  fprintf (stderr, HOST_PTR_PRINTF, lvl->blocks);
+  fprintf (stderr, HOST_PTR_PRINTF, (void *) lvl->blocks);
   fprintf (stderr, " n_incomplete=%d parm_flag=%d keep=%d",
 	   list_length (lvl->incomplete), lvl->parm_flag, lvl->keep);
   if (lvl->tag_transparent)
@@ -1606,7 +1608,7 @@
   for (level = stack; level != global_binding_level; level = level->level_chain)
     {
       fprintf (stderr, "binding level ");
-      fprintf (stderr, HOST_PTR_PRINTF, level);
+      fprintf (stderr, HOST_PTR_PRINTF, (void *) level);
       fprintf (stderr, "\n");
       print_binding_level (level);
     }
@@ -1617,11 +1619,11 @@
 {
   struct binding_level *b;
   fprintf (stderr, "current_binding_level=");
-  fprintf (stderr, HOST_PTR_PRINTF, current_binding_level);
+  fprintf (stderr, HOST_PTR_PRINTF, (void *) current_binding_level);
   fprintf (stderr, "\nclass_binding_level=");
-  fprintf (stderr, HOST_PTR_PRINTF, class_binding_level);
+  fprintf (stderr, HOST_PTR_PRINTF, (void *) class_binding_level);
   fprintf (stderr, "\nglobal_binding_level=");
-  fprintf (stderr, HOST_PTR_PRINTF, global_binding_level);
+  fprintf (stderr, HOST_PTR_PRINTF, (void *) global_binding_level);
   fprintf (stderr, "\n");
   if (class_binding_level)
     {
