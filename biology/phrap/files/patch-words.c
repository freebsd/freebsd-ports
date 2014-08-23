--- ./words.c.orig	2009-04-22 20:48:22.000000000 +0200
+++ ./words.c	2014-08-02 12:39:30.000000000 +0200
@@ -59,6 +59,12 @@
 static unsigned char *long_word_array;
 static int n_skips[3];
 
+void print_word_counts();
+void set_lower_upper();
+void set_index_words(int,int,int);
+void find_external_word_matches(int, unsigned char *);
+void quicksort(SEQ_AREA, SEQ_AREA, int, int, SEQ_AREA *);
+void new_lookup_words(unsigned char *, int, SEQ_AREA, SEQ_AREA, int, int);
 
 typedef struct sw_edge {
   int curr0, curr1, curr2;
@@ -323,6 +329,7 @@
 
 /* only used when DNA_flag == 2 */
 
+void
 set_lower_upper()
 {
   unsigned int word_int, word_reduced, last_word_reduced;
@@ -540,6 +547,7 @@
 /*
  other input: total_length, num_entries, complexity_flag, alphabet_size, residues, minmatch, nlogn_diff, mod_value, index_shift */
 
+void
 set_index_words(pass, trans_type, index_type)
      int pass, trans_type, index_type;
 {
@@ -1070,7 +1078,7 @@
    refinement in Sedgwick, but using bookkeeping of matching leading parts 
    of words in a block to substantially improve
    efficiency) */
-
+void
 quicksort(left, right, k_start, maxcheck, seq_offsets)
      SEQ_AREA left, right;
      int k_start, maxcheck;
@@ -1532,6 +1540,7 @@
 
 */ 
  
+void
 find_external_word_matches(e1, seq) 
      int e1;
      unsigned char *seq;
@@ -1776,6 +1785,7 @@
 int known_match_size, target_match_size, offset1, sub_check, reuse;
 extern int num_pairs;
 
+void
 new_lookup_words(seq1, trans_type, sa_l_lower, sa_u_upper, ss_displace, n_lc)
      int trans_type, ss_displace, n_lc;
      SEQ_AREA sa_l_lower, sa_u_upper;
@@ -2850,6 +2860,7 @@
   for (i = 0; i < 5; i++) num_merge_words[i] = 0;
 }
 
+void
 print_word_counts()
 {
   int i;
