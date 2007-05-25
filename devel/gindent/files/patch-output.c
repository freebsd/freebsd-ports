--- src/output.c.orig	Mon May 21 23:45:36 2007
+++ src/output.c	Mon May 21 23:47:36 2007
@@ -23,7 +23,7 @@
 
 RCSTAG_CC ("$Id: output.c,v 1.5 2002/12/12 17:36:49 david Exp $");
 
-static FILE            * output       = NULL;
+FILE                   * output       = NULL;
 static BOOLEAN           inhibited    = 0;
 static buf_break_st_ty * buf_break_list = NULL;
 
