--- cp/decl.c.orig	Mon Oct 23 15:25:44 1995
+++ cp/decl.c	Mon Mar 20 13:29:12 2000
@@ -1486,7 +1486,7 @@
   tree t;
   int i = 0, len;
   fprintf (stderr, " blocks=");
-  fprintf (stderr, HOST_PTR_PRINTF, lvl->blocks);
+  fprintf (stderr, HOST_PTR_PRINTF, (void *) lvl->blocks);
   fprintf (stderr, " n_incomplete=%d parm_flag=%d keep=%d",
 	   list_length (lvl->incomplete), lvl->parm_flag, lvl->keep);
   if (lvl->tag_transparent)
@@ -1609,7 +1609,7 @@
   for (level = stack; level != global_binding_level; level = level->level_chain)
     {
       fprintf (stderr, "binding level ");
-      fprintf (stderr, HOST_PTR_PRINTF, level);
+      fprintf (stderr, HOST_PTR_PRINTF, (void *) level);
       fprintf (stderr, "\n");
       print_binding_level (level);
     }
@@ -1620,11 +1620,11 @@
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
