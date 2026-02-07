--- src/output.c.orig	2018-09-05 16:47:56 UTC
+++ src/output.c
@@ -74,7 +74,7 @@
 
 RCSTAG_CC ("$Id$");
 
-static FILE            * output       = NULL;
+FILE                   * output       = NULL;
 static BOOLEAN           inhibited    = 0;
 static buf_break_st_ty * buf_break_list = NULL;
 buf_break_st_ty * buf_break = NULL;
