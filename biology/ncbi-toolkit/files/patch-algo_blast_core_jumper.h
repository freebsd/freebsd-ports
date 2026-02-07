--- algo/blast/core/jumper.h.orig	2018-10-19 17:37:04 UTC
+++ algo/blast/core/jumper.h
@@ -66,13 +66,13 @@ typedef struct JumperPrelimEditBlock
 
 
 /** Gapped alignment data needed for jumper */
-typedef struct JumperGapAlign
+struct JumperGapAlign
 {
     JumperPrelimEditBlock* left_prelim_block;
     JumperPrelimEditBlock* right_prelim_block;
     Uint4* table; /**< Table used for matching 4 bases in compressed subject
                        to 4 bases in uncompressed query */
-} JumperGapAlign;
+};
 
 
 JumperGapAlign* JumperGapAlignFree(JumperGapAlign* jumper_align);
@@ -90,11 +90,11 @@ typedef struct JumperEdit
 
 
 /** Alignment edit script for gapped alignment */
-typedef struct JumperEditsBlock
+struct JumperEditsBlock
 {
     JumperEdit* edits;
     Int4 num_edits;
-} JumperEditsBlock;
+};
 
 
 JumperEditsBlock* JumperEditsBlockFree(JumperEditsBlock* block);
@@ -262,13 +262,13 @@ JumperEditsBlock* JumperEditsBlockCombine(JumperEditsB
                                           JumperEditsBlock** append);
 
 /** Structure to save short unaligned subsequences outside an HSP */
-typedef struct SequenceOverhangs
+struct SequenceOverhangs
 {
     Int4 left_len;    /**< Length of the left subsequence */
     Int4 right_len;   /**< Length of the right subsequence */
     Uint1* left;      /**< Left subsequence */
     Uint1* right;     /**< Rught subsequence */
-} SequenceOverhangs;
+};
 
 SequenceOverhangs* SequenceOverhangsFree(SequenceOverhangs* overhangs);
 
