--- src/arch/unix/x11/xaw/widgets/RegExp.c.orig	2009-10-21 18:46:45.000000000 +0200
+++ src/arch/unix/x11/xaw/widgets/RegExp.c	2010-08-02 19:58:49.000000000 +0200
@@ -120,7 +120,6 @@
 /* Dummy for system that don't have neither <regex.h> and <regexp.h>.  */
 
 void RegExpInit(fwf_regex_t *r)
-    ;
 {
     return;
 }
