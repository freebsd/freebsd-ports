--- ./scanner/lex.cc.orig	2013-08-10 10:17:17.000000000 +0200
+++ ./scanner/lex.cc	2013-11-27 19:14:33.000000000 +0100
@@ -2836,7 +2836,7 @@
         {
 #line 192 "lexer"
             {
-    d_number = stoul(d_matched);
+    d_number = A2x(d_matched);
     return Parser::NUMBER;
 }
 
