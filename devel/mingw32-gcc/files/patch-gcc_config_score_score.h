--- gcc/config/score/score.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/score/score.h
@@ -800,7 +800,7 @@ typedef struct score_args
    counter by SIZE bytes.  */
 #undef ASM_OUTPUT_SKIP
 #define ASM_OUTPUT_SKIP(STREAM, SIZE) \
-  fprintf (STREAM, "\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf (STREAM, "\t.space\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* This is how to output an assembler line
    that says to advance the location counter
