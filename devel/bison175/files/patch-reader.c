--- src/reader.c.orig	Mon Jun 14 15:19:05 1999
+++ src/reader.c	Mon Jan 17 03:38:56 2000
@@ -44,6 +44,7 @@
 int rline_allocated;
 
 extern char *program_name;
+extern int broken_undeftoken_init;
 extern int definesflag;
 extern int nolinesflag;
 extern int noparserflag;
@@ -199,7 +200,10 @@
   /* it is always token number 2.  */
   undeftoken = getsym("$undefined.");
   undeftoken->class = STOKEN;
-  undeftoken->user_token_number = 2;
+  /* XXX ``broken_undeftoken_init'' makes Bison 1.28 bug-compatable
+     with Bison 1.25.  FreeBSD depends on this behavior when compiling
+     EGCS-1.1.2's cc1plus.  */
+  undeftoken->user_token_number = broken_undeftoken_init ? 0 : 2;
   /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
      Also notice any %token, %left, etc. found there.  */
   if (noparserflag)
