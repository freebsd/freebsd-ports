--- src/reader.c.orig	Sun Sep 23 02:10:06 2001
+++ src/reader.c	Sun Sep 23 02:08:08 2001
@@ -65,6 +65,8 @@
 
 static bucket *errtoken;
 static bucket *undeftoken;
+
+extern int broken_undeftoken_init;
 
 
 /*===================\
@@ -1959,7 +1961,10 @@
      It is always token number 2.  */
   undeftoken = getsym ("$undefined.");
   undeftoken->class = token_sym;
-  undeftoken->user_token_number = 2;
+  /* XXX ``broken_undeftoken_init'' makes Bison 1.29 bug-compatable
+     with Bison 1.25.  FreeBSD depends on this behavior when compiling
+     EGCS-1.1.2's cc1plus.  */
+  undeftoken->user_token_number = broken_undeftoken_init ? 0 : 2;
 
   /* Read the declaration section.  Copy %{ ... %} groups to
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
