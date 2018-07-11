--- samtools-0.1.18/bam_aux.c.orig	2018-03-06 16:29:49 UTC
+++ samtools-0.1.18/bam_aux.c
@@ -25,7 +25,7 @@ uint8_t *bam_aux_get_core(bam1_t *b, con
 	return bam_aux_get(b, tag);
 }
 
-inline int aux_type2size(uint8_t type)
+int aux_type2size(uint8_t type)
 {
     switch (type) {
     case 'A': case 'c': case 'C':
@@ -43,7 +43,7 @@ inline int aux_type2size(uint8_t type)
     }
 }
 
-inline uint8_t* skip_aux(uint8_t* s) {
+uint8_t* skip_aux(uint8_t* s) {
 	int size = aux_type2size(*s); ++s; // skip type
 	uint32_t n;
 	switch (size) {
