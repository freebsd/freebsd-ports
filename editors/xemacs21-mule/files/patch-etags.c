Index: lib-src/etags.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lib-src/etags.c,v
retrieving revision 1.24.2.2
retrieving revision 1.24.2.3
diff -u -r1.24.2.2 -r1.24.2.3
--- lib-src/etags.c	2004/06/24 04:02:29	1.24.2.2
+++ lib-src/etags.c	2004/12/17 23:03:25	1.24.2.3
@@ -5146,6 +5146,7 @@
      bool ignore_case;
      language *lang;
 {
+  static struct re_pattern_buffer zeropattern;
   char *name;
   const char *err;
   struct re_pattern_buffer *patbuf;
@@ -5166,11 +5167,9 @@
   (void) scan_separators (name);
 
   patbuf = xnew (1, struct re_pattern_buffer);
+  *patbuf = zeropattern;
   /* Translation table to fold case if appropriate. */
   patbuf->translate = (ignore_case) ? lc_trans : NULL;
-  patbuf->fastmap = NULL;
-  patbuf->buffer = NULL;
-  patbuf->allocated = 0;
 
   err = re_compile_pattern (regexp_pattern, strlen (regexp_pattern), patbuf);
   if (err != NULL)
