$NetBSD: patch-am,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_terminfo.c.orig	2007-05-15 19:03:32.000000000 +0000
+++ src/libmojave-external/cutil/lm_terminfo.c
@@ -75,9 +75,9 @@ value caml_tgetstr(value id) {
 
    /* Note that tigetstr will return either 0 or -1 on error. */
    if(termdata == NULL || termdata == (char *)(-1)) {
-      result = copy_string("");
+      result = caml_copy_string("");
    } else {
-      result = copy_string(termdata);
+      result = caml_copy_string(termdata);
       /* apparently we're not supposed to free termdata here */
       /* TEMP:  I cannot find specs on this! */
       //free(termdata);
