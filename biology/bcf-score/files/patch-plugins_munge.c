--- plugins/munge.c.orig	2023-07-16 07:57:54 UTC
+++ plugins/munge.c
@@ -120,7 +120,7 @@ int tsv_read_string(tsv_t *tsv, bcf1_t *rec, void *usr
     return 0;
 }
 
-static const int (*tsv_setters[])(tsv_t *tsv, bcf1_t *rec, void *usr) = {tsv_setter_id_flexible,         // SNP
+static int (*tsv_setters[])(tsv_t *tsv, bcf1_t *rec, void *usr) = {tsv_setter_id_flexible,         // SNP
                                                                          tsv_setter_pos_flexible,        // BP
                                                                          tsv_setter_chrom_flexible,      // CHR
                                                                          tsv_read_allele,                // A1
