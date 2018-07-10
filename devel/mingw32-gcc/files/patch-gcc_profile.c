--- gcc/profile.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/profile.c
@@ -398,7 +398,7 @@ is_edge_inconsistent (vec<edge, va_gc> *
 	      if (dump_file)
 		{
 		  fprintf (dump_file,
-		  	   "Edge %i->%i is inconsistent, count"HOST_WIDEST_INT_PRINT_DEC,
+		  	   "Edge %i->%i is inconsistent, count" HOST_WIDEST_INT_PRINT_DEC,
 			   e->src->index, e->dest->index, e->count);
 		  dump_bb (dump_file, e->src, 0, TDF_DETAILS);
 		  dump_bb (dump_file, e->dest, 0, TDF_DETAILS);
@@ -459,7 +459,7 @@ is_inconsistent (void)
 	  if (dump_file)
 	    {
 	      fprintf (dump_file, "BB %i count does not match sum of incoming edges "
-		       HOST_WIDEST_INT_PRINT_DEC" should be " HOST_WIDEST_INT_PRINT_DEC,
+		       HOST_WIDEST_INT_PRINT_DEC " should be " HOST_WIDEST_INT_PRINT_DEC,
 		       bb->index,
 		       bb->count,
 		       sum_edge_counts (bb->preds));
@@ -473,7 +473,7 @@ is_inconsistent (void)
 	  if (dump_file)
 	    {
 	      fprintf (dump_file, "BB %i count does not match sum of outgoing edges "
-		       HOST_WIDEST_INT_PRINT_DEC" should be " HOST_WIDEST_INT_PRINT_DEC,
+		       HOST_WIDEST_INT_PRINT_DEC " should be " HOST_WIDEST_INT_PRINT_DEC,
 		       bb->index,
 		       bb->count,
 		       sum_edge_counts (bb->succs));
