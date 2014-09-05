--- ./analyze_splices.c.orig	2008-08-31 03:37:44.000000000 +0200
+++ ./analyze_splices.c	2014-08-02 12:39:30.000000000 +0200
@@ -146,6 +146,13 @@
 char *exon_seq;
 double base_llr, intron_coeff;
 
+void find_left_sites(Aligned_pair *, Cand_pair *, char *, char *);
+void find_right_sites(Aligned_pair *, Cand_pair *, char *, char *);
+void increment_splice_site(unsigned char *, unsigned char *,
+	Aligned_pair *, int, int, int, unsigned char *, int);
+void scan(Splice_site *, Aligned_pair *, unsigned char *,
+	int, int, int, int);
+
 set_splice_params()
 {
   int i, j;
@@ -186,6 +193,7 @@
    cases of large missing exons: want to make sure this part of read doesn't match somewhere else, instead
 */
 
+void
 append_cand_splice(strand, left_splice_site, right_splice_site, overlap, intron_length, left_pair, right_pair)
      int strand, overlap, intron_length;
      Splice_site *left_splice_site, *right_splice_site;
@@ -512,6 +520,7 @@
   return penalty;
 }
 
+void
 check_best_site(pair, side, cand_pair)
   Aligned_pair *pair;
   int side;
@@ -560,6 +569,7 @@
 
 int extend[3];
 
+void
 find_left_sites(pair, cand_pair, seq1, seq2)
   Aligned_pair *pair;
   Cand_pair *cand_pair;
@@ -651,6 +661,7 @@
 
 }
 
+void
 find_right_sites(pair, cand_pair, seq1, seq2)
   Aligned_pair *pair;
   Cand_pair *cand_pair;
@@ -816,6 +827,7 @@
 This doesn't really address multiple testing issue; 
 */
 
+void
 increment_splice_site(seq1, seq2, pair, strand, side, loc, seq, type)
      Aligned_pair *pair;
      int strand, side, loc, type;
@@ -922,6 +934,7 @@
 
 /* input: splice_site, c_len, pair, seq1, exon_seq, genome_overhang, cdna_overhang, base_llr, intron_coeff, max_i  */
 
+void
 scan(splice_site, pair, seq1, genome_overhang, cdna_overhang, max_i, test_len)
   Splice_site *splice_site;
   Aligned_pair *pair;
@@ -1098,6 +1111,7 @@
   return n_matches;
 }
 
+void
 check_max_length(length)
      int length;
 {
@@ -1118,6 +1132,7 @@
   max_length = length;
 }
 
+void
 filter_matches(i_ptr, n_p, pair_pointers, print_flag)
      int i_ptr, n_p, print_flag;
      Aligned_pair **pair_pointers;
@@ -1276,6 +1291,7 @@
   return seg_equiv1->start - seg_equiv2->start;
 }
 
+void
 analyze_multiple(i_ptr, n_p, pair_pointers, print_flag)
      int i_ptr, n_p, print_flag;
      Aligned_pair **pair_pointers;
