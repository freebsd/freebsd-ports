--- plugins/score.c.orig	2023-07-16 08:04:54 UTC
+++ plugins/score.c
@@ -140,7 +140,7 @@ static int tsv_read_allele(tsv_t *tsv, bcf1_t *rec, vo
     return 0;
 }
 
-static const int (*tsv_setters[])(tsv_t *tsv, bcf1_t *rec, void *usr) = {tsv_setter_id_flexible,         // SNP
+static int (*tsv_setters[])(tsv_t *tsv, bcf1_t *rec, void *usr) = {tsv_setter_id_flexible,         // SNP
                                                                          tsv_setter_pos_flexible,        // BP
                                                                          tsv_setter_chrom_flexible,      // CHR
                                                                          tsv_read_allele,                // A1
