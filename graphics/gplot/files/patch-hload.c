--- hload.c.orig	Thu Jul 18 02:22:04 1991
+++ hload.c	Sat Jun 16 01:03:27 2007
@@ -5,6 +5,10 @@
 #include "defs.h"
 #define END_FLAG 0
 
+static do_vecs();
+static send_vecs();
+static dim_str();
+
 /* show a character */
 static show_char(font_no, char_no)
 int font_no, char_no;
