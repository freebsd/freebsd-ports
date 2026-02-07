--- genotype.cpp.orig	2020-07-27 13:47:27 UTC
+++ genotype.cpp
@@ -301,7 +301,7 @@ class Igor : Program
                             //already present
                             free(qname);
                         }
-                        kh_val(reads, k) = {bam_get_pos1(s), bam_get_pos1(s)+bam_get_l_qseq(s)-1};
+                        kh_val(reads, k) = {(int32_t)bam_get_pos1(s), (int32_t)bam_get_pos1(s)+bam_get_l_qseq(s)-1};
                     }
                 }
                 else
