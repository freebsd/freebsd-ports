--- gcc/profile.c.orig	2014-02-01 08:40:31 UTC
+++ gcc/profile.c
@@ -318,7 +318,7 @@ is_edge_inconsistent (vec<edge, va_gc> *
 	      if (dump_file)
 		{
 		  fprintf (dump_file,
-		  	   "Edge %i->%i is inconsistent, count"HOST_WIDEST_INT_PRINT_DEC,
+		  	   "Edge %i->%i is inconsistent, count" HOST_WIDEST_INT_PRINT_DEC,
 			   e->src->index, e->dest->index, e->count);
 		  dump_bb (dump_file, e->src, 0, TDF_DETAILS);
 		  dump_bb (dump_file, e->dest, 0, TDF_DETAILS);
@@ -379,7 +379,7 @@ is_inconsistent (void)
 	  if (dump_file)
 	    {
 	      fprintf (dump_file, "BB %i count does not match sum of incoming edges "
-		       HOST_WIDEST_INT_PRINT_DEC" should be " HOST_WIDEST_INT_PRINT_DEC,
+		       HOST_WIDEST_INT_PRINT_DEC " should be " HOST_WIDEST_INT_PRINT_DEC,
 		       bb->index,
 		       bb->count,
 		       sum_edge_counts (bb->preds));
@@ -394,7 +394,7 @@ is_inconsistent (void)
 	  if (dump_file)
 	    {
 	      fprintf (dump_file, "BB %i count does not match sum of outgoing edges "
-		       HOST_WIDEST_INT_PRINT_DEC" should be " HOST_WIDEST_INT_PRINT_DEC,
+		       HOST_WIDEST_INT_PRINT_DEC " should be " HOST_WIDEST_INT_PRINT_DEC,
 		       bb->index,
 		       bb->count,
 		       sum_edge_counts (bb->succs));
