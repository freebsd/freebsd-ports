--- gcc/cp/decl2.c.orig	Thu Aug 19 16:29:45 1999
+++ gcc/cp/decl2.c	Sun Nov 26 15:21:44 2000
@@ -281,6 +281,7 @@
 /* Warn about *printf or *scanf format/argument anomalies.  */
 
 int warn_format;
+int warn_format_extra_args = 1;
 
 /* Warn about a subscript that has type char.  */
 
