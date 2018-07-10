--- gcc/tree-ssa-structalias.c.orig	2013-02-04 13:31:28 UTC
+++ gcc/tree-ssa-structalias.c
@@ -6005,14 +6005,14 @@ dump_pta_stats (FILE *s)
 {
   fprintf (s, "\nPTA query stats:\n");
   fprintf (s, "  pt_solution_includes: "
-	   HOST_WIDE_INT_PRINT_DEC" disambiguations, "
-	   HOST_WIDE_INT_PRINT_DEC" queries\n",
+	   HOST_WIDE_INT_PRINT_DEC " disambiguations, "
+	   HOST_WIDE_INT_PRINT_DEC " queries\n",
 	   pta_stats.pt_solution_includes_no_alias,
 	   pta_stats.pt_solution_includes_no_alias
 	   + pta_stats.pt_solution_includes_may_alias);
   fprintf (s, "  pt_solutions_intersect: "
-	   HOST_WIDE_INT_PRINT_DEC" disambiguations, "
-	   HOST_WIDE_INT_PRINT_DEC" queries\n",
+	   HOST_WIDE_INT_PRINT_DEC " disambiguations, "
+	   HOST_WIDE_INT_PRINT_DEC " queries\n",
 	   pta_stats.pt_solutions_intersect_no_alias,
 	   pta_stats.pt_solutions_intersect_no_alias
 	   + pta_stats.pt_solutions_intersect_may_alias);
