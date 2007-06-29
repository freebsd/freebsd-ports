--- examples/util/text.c.orig	Fri Jan 13 04:13:46 1995
+++ examples/util/text.c	Fri Jun 29 17:15:09 2007
@@ -56,6 +56,8 @@
 words, the string "H   ,(2)   O" will give the same results as "H,(2)O".
 */
 
+static int gettok();
+
 DtObject subscript (
     char *str)
 {
