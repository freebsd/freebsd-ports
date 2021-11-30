--- example.c.orig	2021-11-30 15:26:24 UTC
+++ example.c
@@ -44,7 +44,7 @@ int main(int argc, char *argv[])
 			for (j = 0; j < n_reg; ++j) { // traverse hits and print them out
 				mm_reg1_t *r = &reg[j];
 				assert(r->p); // with MM_F_CIGAR, this should not be NULL
-				printf("%s\t%d\t%d\t%d\t%c\t", ks->name.s, ks->seq.l, r->qs, r->qe, "+-"[r->rev]);
+				printf("%s\t%zu\t%d\t%d\t%c\t", ks->name.s, ks->seq.l, r->qs, r->qe, "+-"[r->rev]);
 				printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\tcg:Z:", mi->seq[r->rid].name, mi->seq[r->rid].len, r->rs, r->re, r->mlen, r->blen, r->mapq);
 				for (i = 0; i < r->p->n_cigar; ++i) // IMPORTANT: this gives the CIGAR in the aligned regions. NO soft/hard clippings!
 					printf("%d%c", r->p->cigar[i]>>4, MM_CIGAR_STR[r->p->cigar[i]&0xf]);
