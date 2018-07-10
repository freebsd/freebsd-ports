--- gcc/tree-ssa-reassoc.c.orig	2013-05-07 14:43:17 UTC
+++ gcc/tree-ssa-reassoc.c
@@ -3795,7 +3795,7 @@ attempt_builtin_powi (gimple stmt, vec<o
 		      if (elt < vec_len - 1)
 			fputs (" * ", dump_file);
 		    }
-		  fprintf (dump_file, ")^"HOST_WIDE_INT_PRINT_DEC"\n",
+		  fprintf (dump_file, ")^" HOST_WIDE_INT_PRINT_DEC "\n",
 			   power);
 		}
 	    }
@@ -3829,7 +3829,7 @@ attempt_builtin_powi (gimple stmt, vec<o
 		  if (elt < vec_len - 1)
 		    fputs (" * ", dump_file);
 		}
-	      fprintf (dump_file, ")^"HOST_WIDE_INT_PRINT_DEC"\n", power);
+	      fprintf (dump_file, ")^" HOST_WIDE_INT_PRINT_DEC "\n", power);
 	    }
 
 	  reassociate_stats.pows_created++;
