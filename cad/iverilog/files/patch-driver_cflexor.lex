--- driver/cflexor.lex.orig	2020-08-18 17:06:30 UTC
+++ driver/cflexor.lex
@@ -30,6 +30,7 @@
 static int comment_enter;
 static char* trim_trailing_white(char*txt, int trim);
 
+char *current_file;
 /*
  * Mostly copied from the flex manual. Do not make this arbitrary
  * depth without checking for looping files.
