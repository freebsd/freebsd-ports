--- read_filter.cpp.orig	2020-07-27 13:49:14 UTC
+++ read_filter.cpp
@@ -92,7 +92,7 @@ bool ReadFilter::filter_read(bam_hdr_t* h, bam1_t *s)
                         //already present
                         free(qname);
                     }
-                    kh_val(reads, k) = {bam_get_pos1(s), bam_get_pos1(s)+bam_get_l_qseq(s)-1};
+                    kh_val(reads, k) = {(int32_t)bam_get_pos1(s), (int32_t)bam_get_pos1(s)+bam_get_l_qseq(s)-1};
                 }
             }
             else
@@ -272,4 +272,4 @@ void ReadFilter::bam_print_key_values(bam_hdr_t *h, ba
     if (qual.m) free(qual.s);
     if (cigar_string.m) free(cigar_string.s);
     if (cigar_expanded_string.m) free(cigar_expanded_string.s);
-}
\ No newline at end of file
+}
