--- src/paml.h.orig	2020-08-20 16:14:50 UTC
+++ src/paml.h
@@ -372,9 +372,9 @@ void copySptree(void);
 void printSptree(void);
 
 
-enum {BASEseq=0, CODONseq, AAseq, CODON2AAseq, BINARYseq, BASE5seq} SeqTypes;
+enum SeqTypes {BASEseq=0, CODONseq, AAseq, CODON2AAseq, BINARYseq, BASE5seq};
 
-enum {PrBranch=1, PrNodeNum=2, PrLabel=4, PrNodeStr=8, PrAge=16, PrOmega=32} OutTreeOptions;
+enum OutTreeOptions {PrBranch=1, PrNodeNum=2, PrLabel=4, PrNodeStr=8, PrAge=16, PrOmega=32};
 
 
 /* use mean (0; default) for discrete gamma instead of median (1) */
