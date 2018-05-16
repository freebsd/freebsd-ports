--- src/libfastx/fastx.h.orig	2018-05-16 14:50:08 UTC
+++ src/libfastx/fastx.h
@@ -58,7 +58,7 @@ typedef enum {
 	OUTPUT_SAME_AS_INPUT=3
 } OUTPUT_FILE_TYPE;
 
-#pragma pack(1) 
+#pragma pack(push,1) 
 typedef struct 
 {
 	/* Record data - common for FASTA/FASTQ */
@@ -115,6 +115,7 @@ typedef struct 
 	FILE*	input;
 	FILE*	output;
 } FASTX ;
+#pragma pack(pop)
 
 
 void fastx_init_reader(FASTX *pFASTX, const char* filename, 
