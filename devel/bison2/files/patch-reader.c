--- src/reader.c.orig	Thu Feb  7 09:12:44 2002
+++ src/reader.c	Sat Feb 16 19:49:02 2002
@@ -34,6 +34,8 @@
 #include "reader.h"
 #include "conflicts.h"
 
+extern int broken_undeftoken_init;
+
 typedef struct symbol_list
 {
   struct symbol_list *next;
@@ -1978,7 +1979,10 @@
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
