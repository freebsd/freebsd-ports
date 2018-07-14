--- gcc/cgraph.c.orig	2014-06-20 09:57:53 UTC
+++ gcc/cgraph.c
@@ -1378,7 +1378,7 @@ cgraph_redirect_edge_call_stmt_to_callee
 	  if (dump_file)
 	    fprintf (dump_file,
 		     "Expanding speculative call of %s/%i -> %s/%i count:"
-		     HOST_WIDEST_INT_PRINT_DEC"\n",
+		     HOST_WIDEST_INT_PRINT_DEC "\n",
 		     xstrdup (e->caller->name ()),
 		     e->caller->order,
 		     xstrdup (e->callee->name ()),
@@ -1976,7 +1976,7 @@ dump_cgraph_node (FILE *f, struct cgraph
   fprintf (f, "  First run: %i\n", node->tp_first_run);
   fprintf (f, "  Function flags:");
   if (node->count)
-    fprintf (f, " executed "HOST_WIDEST_INT_PRINT_DEC"x",
+    fprintf (f, " executed " HOST_WIDEST_INT_PRINT_DEC "x",
 	     (HOST_WIDEST_INT)node->count);
   if (node->origin)
     fprintf (f, " nested in: %s", node->origin->asm_name ());
@@ -2028,7 +2028,7 @@ dump_cgraph_node (FILE *f, struct cgraph
       fprintf (f, "%s/%i ", edge->caller->asm_name (),
 	       edge->caller->order);
       if (edge->count)
-	fprintf (f, "("HOST_WIDEST_INT_PRINT_DEC"x) ",
+	fprintf (f, "(" HOST_WIDEST_INT_PRINT_DEC "x) ",
 		 (HOST_WIDEST_INT)edge->count);
       if (edge->frequency)
 	fprintf (f, "(%.2f per call) ",
@@ -2055,7 +2055,7 @@ dump_cgraph_node (FILE *f, struct cgraph
       if (edge->indirect_inlining_edge)
 	fprintf (f, "(indirect_inlining) ");
       if (edge->count)
-	fprintf (f, "("HOST_WIDEST_INT_PRINT_DEC"x) ",
+	fprintf (f, "(" HOST_WIDEST_INT_PRINT_DEC "x) ",
 		 (HOST_WIDEST_INT)edge->count);
       if (edge->frequency)
 	fprintf (f, "(%.2f per call) ",
