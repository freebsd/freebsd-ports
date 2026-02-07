--- ./db.c.orig	2009-04-21 18:10:09.000000000 +0200
+++ ./db.c	2014-08-02 12:39:30.000000000 +0200
@@ -38,6 +38,8 @@
 int qseq_trans[256];
 int t_num_entries;
 
+void size_conflict(SEQ_AREA,long int,char *);
+
 typedef long int POS;
 static POS id_pos, descrip_pos, seq_pos, seq_length;
 /* N.B. following needed by Bonfield code, so original "static" designation has
@@ -571,6 +573,7 @@
 	 (unsigned long int)db->seq_area_size, (unsigned long int)db->id_area_size, (unsigned long int)db->descrip_area_size);
 }
 
+void
 size_conflict(size1, size2, label)
      SEQ_AREA size1;
      long int size2;
