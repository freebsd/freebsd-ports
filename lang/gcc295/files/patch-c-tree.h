--- gcc/c-tree.h.orig	Thu Feb 18 12:38:43 1999
+++ gcc/c-tree.h	Sun Nov 26 15:21:36 2000
@@ -495,6 +495,7 @@
 /* Warn about *printf or *scanf format/argument anomalies. */
 
 extern int warn_format;
+extern int warn_format_extra_args;
 
 /* Warn about a subscript that has type char.  */
 
