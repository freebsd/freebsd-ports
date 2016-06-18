--- token.c.orig	2016-06-14 16:25:53 UTC
+++ token.c
@@ -67,7 +67,7 @@ void insert_token(Ttoken *list, Ttoken *
 
 // tokenizes the string str
 Ttoken *tokenize(char *str) {
-    Ttoken *tok_list, *tok_tmp;
+    Ttoken *tok_list, *tok_tmp = NULL;
     char word[256];
     int a, b, c;
     int i = 0;
