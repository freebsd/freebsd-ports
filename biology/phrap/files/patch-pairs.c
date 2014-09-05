--- ./pairs.c.orig	2009-04-23 00:12:20.000000000 +0200
+++ ./pairs.c	2014-08-02 12:39:30.000000000 +0200
@@ -37,6 +37,16 @@
 int single_domain;
 double mask_frac;
 
+void revise_qd_scores(Query_domain *);
+void visit_cand_pairs_scores( Cand_pair *);
+void merge_qds(Database *, int);
+void init_qd_trims(Query_domain *);
+void test_qd1_merges(Query_domain *, Query_domain *);
+void test_qd2_merges(Query_domain *, Query_domain *);
+void compare_query_domains(Query_domain *, Query_domain *);
+void print_score_list(int, Query_domain *);
+void print_pair(Aligned_pair *, FILE *, int);
+
 set_domain_vars()
 {
   single_domain = parameters->masklevel == 0 || parameters->masklevel == 101;
@@ -697,6 +707,7 @@
 																						  */
 }
 
+void
 visit_cand_pairs_scores(cand_pair)
      Cand_pair *cand_pair;
 {
@@ -1423,6 +1434,7 @@
 
 int trim_flag;
 
+void
 merge_qds(db, t_f)
      Database *db;
      int t_f;
@@ -1463,6 +1475,7 @@
   }
 }
 
+void
 init_qd_trims(query_domain)
      Query_domain *query_domain;
 {
@@ -1476,6 +1489,7 @@
   init_qd_trims(query_domain->child[1]);
 }
 
+void
 test_qd1_merges(query_domain1, query_domain2)
      Query_domain *query_domain1, *query_domain2;
 {
@@ -1486,6 +1500,7 @@
   test_qd1_merges(query_domain1->child[1], query_domain2);
 }
 
+void
 test_qd2_merges(query_domain1, query_domain2)
      Query_domain *query_domain1, *query_domain2;
 {
@@ -1533,6 +1548,7 @@
   }
 }
 
+void
 compare_query_domains(query_domain1, query_domain2)
   Query_domain *query_domain1, *query_domain2;
 {
@@ -1570,6 +1586,7 @@
   }
 }
 
+void
 print_score_list(entry, query_domain)
      int entry;
      Query_domain *query_domain;
@@ -1732,6 +1749,7 @@
   }
 }
 
+void
 print_pair(pair, fp, no_zero)
      Aligned_pair *pair;
      FILE *fp;
@@ -4125,6 +4143,7 @@
   notify("done");
 }
 
+void
 revise_qd_scores(query_domain)
      Query_domain *query_domain;
 {
