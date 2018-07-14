--- gcc/tree-ssa-reassoc.c.orig	2018-07-13 23:29:13 UTC
+++ gcc/tree-ssa-reassoc.c
@@ -4208,7 +4208,7 @@ attempt_builtin_powi (gimple stmt, vec<o
 		      if (elt < vec_len - 1)
 			fputs (" * ", dump_file);
 		    }
-		  fprintf (dump_file, ")^"HOST_WIDE_INT_PRINT_DEC"\n",
+		  fprintf (dump_file, ")^" HOST_WIDE_INT_PRINT_DEC "\n",
 			   power);
 		}
 	    }
@@ -4242,7 +4242,7 @@ attempt_builtin_powi (gimple stmt, vec<o
 		  if (elt < vec_len - 1)
 		    fputs (" * ", dump_file);
 		}
-	      fprintf (dump_file, ")^"HOST_WIDE_INT_PRINT_DEC"\n", power);
+	      fprintf (dump_file, ")^" HOST_WIDE_INT_PRINT_DEC "\n", power);
 	    }
 
 	  reassociate_stats.pows_created++;
