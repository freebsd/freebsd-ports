--- src/output.c.orig	2008-03-11 18:50:42 UTC
+++ src/output.c
@@ -71,7 +71,7 @@
 
 RCSTAG_CC ("$Id$");
 
-static FILE            * output       = NULL;
+FILE                   * output       = NULL;
 static BOOLEAN           inhibited    = 0;
 static buf_break_st_ty * buf_break_list = NULL;
 
