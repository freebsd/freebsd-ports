--- extvars.h.orig	2001-12-27 22:19:58 UTC
+++ extvars.h
@@ -129,10 +129,10 @@ extern int numb_moves;
 
 extern int phase;
 
-FILE *lrn_standard;
-FILE *lrn_zh;
-FILE *lrn_suicide;
-FILE *lrn_losers;
+extern FILE *lrn_standard;
+extern FILE *lrn_zh;
+extern FILE *lrn_suicide;
+extern FILE *lrn_losers;
 extern int bestmovenum;
 
 extern int ugly_ep_hack;
