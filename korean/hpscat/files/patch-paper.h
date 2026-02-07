--- paper.h.orig	1995-11-23 07:56:27 UTC
+++ paper.h
@@ -5,7 +5,7 @@ typedef struct { char name[12];
    add other paper types like b4 and b5  before the last entry 'user' here 
    and their dimensions to the array  'papersize' in paper.c */
 typedef enum {a3,a4,a5,b4,b5,letter,t10x14,legal,executive,
-              folio,quarto,statement,ledger,tabloid,user} PAPER; 
+              folio,quarto,statement,ledger,tabloid,c5,user} PAPER; 
 
 /* mnemonics for length unit  
    add other unit such as pica  and conversion factor to standard
@@ -54,8 +54,8 @@ extern void setmargin();
 #define ABS_MIN_LM 18  /* depends on printer */ 
 
 
-extern s_width;
-extern s_width_nl;
+extern int s_width;
+extern int s_width_nl;
 extern int l_width,l_height,l_lm1,l_lm2,l_bm,l_tm;
 extern int l3_width,l3_height,l3_lm1,l3_lm2,l3_lm3,l3_bm,l3_tm;
 extern int p_width,p_height,p_lm,p_bm,p_tm;
