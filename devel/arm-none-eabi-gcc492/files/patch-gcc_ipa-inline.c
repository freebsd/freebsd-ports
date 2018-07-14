--- gcc/ipa-inline.c.orig	2014-05-21 05:40:09 UTC
+++ gcc/ipa-inline.c
@@ -1727,7 +1727,7 @@ inline_small_functions (void)
 		   badness,
 		   edge->frequency / (double)CGRAPH_FREQ_BASE);
 	  if (edge->count)
-	    fprintf (dump_file," Called "HOST_WIDEST_INT_PRINT_DEC"x\n",
+	    fprintf (dump_file," Called " HOST_WIDEST_INT_PRINT_DEC "x\n",
 		     edge->count);
 	  if (dump_flags & TDF_DETAILS)
 	    edge_badness (edge, true);
