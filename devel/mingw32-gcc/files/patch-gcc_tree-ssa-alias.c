--- gcc/tree-ssa-alias.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/tree-ssa-alias.c
@@ -109,20 +109,20 @@ dump_alias_stats (FILE *s)
 {
   fprintf (s, "\nAlias oracle query stats:\n");
   fprintf (s, "  refs_may_alias_p: "
-	   HOST_WIDE_INT_PRINT_DEC" disambiguations, "
-	   HOST_WIDE_INT_PRINT_DEC" queries\n",
+	   HOST_WIDE_INT_PRINT_DEC " disambiguations, "
+	   HOST_WIDE_INT_PRINT_DEC " queries\n",
 	   alias_stats.refs_may_alias_p_no_alias,
 	   alias_stats.refs_may_alias_p_no_alias
 	   + alias_stats.refs_may_alias_p_may_alias);
   fprintf (s, "  ref_maybe_used_by_call_p: "
-	   HOST_WIDE_INT_PRINT_DEC" disambiguations, "
-	   HOST_WIDE_INT_PRINT_DEC" queries\n",
+	   HOST_WIDE_INT_PRINT_DEC " disambiguations, "
+	   HOST_WIDE_INT_PRINT_DEC " queries\n",
 	   alias_stats.ref_maybe_used_by_call_p_no_alias,
 	   alias_stats.refs_may_alias_p_no_alias
 	   + alias_stats.ref_maybe_used_by_call_p_may_alias);
   fprintf (s, "  call_may_clobber_ref_p: "
-	   HOST_WIDE_INT_PRINT_DEC" disambiguations, "
-	   HOST_WIDE_INT_PRINT_DEC" queries\n",
+	   HOST_WIDE_INT_PRINT_DEC " disambiguations, "
+	   HOST_WIDE_INT_PRINT_DEC " queries\n",
 	   alias_stats.call_may_clobber_ref_p_no_alias,
 	   alias_stats.call_may_clobber_ref_p_no_alias
 	   + alias_stats.call_may_clobber_ref_p_may_alias);
