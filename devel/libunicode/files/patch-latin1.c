--- latin1.c.orig	Wed Jun  5 02:41:15 2002
+++ latin1.c	Wed Jun  5 02:41:34 2002
@@ -89,7 +89,7 @@
 }
 
 /* The encoding descriptor for Latin1.  */
-static char *l1n[] = { "8859-1", "ISO-8859-1", NULL };
+static char *l1n[] = { "8859-1", "ISO8859-1", "ISO_8859-1", "ISO-8859-1", NULL };
 unicode_encoding_t unicode_latin1_encoding =
 {
   l1n,
