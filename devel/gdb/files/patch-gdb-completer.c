--- gdb/completer.c.orig	2022-10-18 21:49:26.647324000 +0200
+++ gdb/completer.c	2022-10-18 22:07:35.218698000 +0200
@@ -2011,7 +2011,7 @@
       rl_basic_quote_characters = NULL;
     }
 
-  return rl_completer_word_break_characters;
+  return (char *)rl_completer_word_break_characters;
 }
 
 char *
