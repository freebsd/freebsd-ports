--- edit.c.orig	2014-02-21 07:38:19.000000000 +0800
+++ edit.c	2014-02-21 07:38:29.000000000 +0800
@@ -988,7 +988,7 @@
       redraw_everything = YEA;
 }
 
-match_paren()
+void match_paren()
 {
    static char parens[] = "()[]{}<>";
    int type, mode;
