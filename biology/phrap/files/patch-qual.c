--- ./qual.c.orig	2008-11-12 17:45:48.000000000 +0100
+++ ./qual.c	2014-08-02 12:39:30.000000000 +0200
@@ -44,6 +44,12 @@
 static int mismatch_LLR[256];
 double *scaled_err_probs; /* used for finding high-quality segments */
 
+void read_qual(Database *);
+void rescale_qual(Database *);
+void incr_diff_hist(unsigned char *, unsigned char *,
+	int, int, int, int, 
+	int, int, int, int );
+
 init_qual_arrays()
 {
   int i;
@@ -580,6 +586,7 @@
 }
 
 /* read in quality data */
+void
 read_qual(db)
      Database *db;
 {
@@ -876,6 +883,7 @@
 }
 
 /* NOT CORRECT WITH COMPRESSED QUAL */
+void
 rescale_qual(db)
      Database *db;
 {
@@ -1153,6 +1161,10 @@
   int conf_count[2], conf_max_score, conf_max_margin; /* # confirming reads */
 } Diffsegnode;
 
+void append_diffdata(Diffsegnode *);
+void append_diffsegnode(Diffsegnode *, int, int, int, int, Diffsegnode *);
+void write_diffsegnode(Diffsegnode *);
+
 int data_type, data_length, data_qual, data_reverse, data_score, data_margin;
 unsigned char *data_seq;
 
@@ -1400,6 +1412,7 @@
       = n_align[i] = n_unalign[i] = n_p_unalign[i] = 0;
 }
  
+void
 incr_diff_hist(seq, diff, length1, length2, start1, start2, end1, end2, reverse, ignore_ends)
      unsigned char *seq;
      unsigned char *diff;
@@ -1543,6 +1556,7 @@
 int node_index;
 extern unsigned char area_comp_mat[];
 
+void
 append_diffdata(diffsegnode)
      Diffsegnode *diffsegnode;
 {
@@ -1607,6 +1621,7 @@
   diffdata->count[!data_reverse] = 0;
 }
 
+void
 append_diffsegnode(node, entry, seg_start, seg_end, conf_flag, data_node)
      Diffsegnode *node, *data_node; /* latter is 0 if reading from global vars */
      int entry, seg_start, seg_end, conf_flag;
@@ -1724,6 +1739,7 @@
   strcpy(cdb, "CDSILRdi");
 }
 
+void
 write_diffsegnode(node)
      Diffsegnode *node;
 {
@@ -1800,6 +1816,7 @@
   write_diffsegnode(node->child[1]);
 }
 
+void
 write_diffsegnodes()
 {
   int i;
