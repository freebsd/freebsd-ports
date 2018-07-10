--- gcc/cgraph.c.orig	2013-05-22 07:50:40 UTC
+++ gcc/cgraph.c
@@ -1513,7 +1513,7 @@ dump_cgraph_node (FILE *f, struct cgraph
   if (node->analyzed)
     fprintf (f, " analyzed");
   if (node->count)
-    fprintf (f, " executed "HOST_WIDEST_INT_PRINT_DEC"x",
+    fprintf (f, " executed " HOST_WIDEST_INT_PRINT_DEC "x",
 	     (HOST_WIDEST_INT)node->count);
   if (node->origin)
     fprintf (f, " nested in: %s", cgraph_node_asm_name (node->origin));
@@ -1565,7 +1565,7 @@ dump_cgraph_node (FILE *f, struct cgraph
       fprintf (f, "%s/%i ", cgraph_node_asm_name (edge->caller),
 	       edge->caller->symbol.order);
       if (edge->count)
-	fprintf (f, "("HOST_WIDEST_INT_PRINT_DEC"x) ",
+	fprintf (f, "(" HOST_WIDEST_INT_PRINT_DEC "x) ",
 		 (HOST_WIDEST_INT)edge->count);
       if (edge->frequency)
 	fprintf (f, "(%.2f per call) ",
@@ -1588,7 +1588,7 @@ dump_cgraph_node (FILE *f, struct cgraph
       if (edge->indirect_inlining_edge)
 	fprintf(f, "(indirect_inlining) ");
       if (edge->count)
-	fprintf (f, "("HOST_WIDEST_INT_PRINT_DEC"x) ",
+	fprintf (f, "(" HOST_WIDEST_INT_PRINT_DEC "x) ",
 		 (HOST_WIDEST_INT)edge->count);
       if (edge->frequency)
 	fprintf (f, "(%.2f per call) ",
