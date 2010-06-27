--- src/output.c.orig	2008-03-11 19:50:42.000000000 +0100
+++ src/output.c	2010-06-27 16:29:17.000000000 +0200
@@ -71,7 +71,7 @@
 
 RCSTAG_CC ("$Id$");
 
-static FILE            * output       = NULL;
+FILE                   * output       = NULL;
 static BOOLEAN           inhibited    = 0;
 static buf_break_st_ty * buf_break_list = NULL;
 
