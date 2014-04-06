--- scanner/lex.cc.orig	2014-04-04 14:46:17.624123806 +0600
+++ scanner/lex.cc	2014-04-04 14:46:39.301107135 +0600
@@ -2702,7 +2702,7 @@
         {
 #line 193 "lexer"
             {
-                d_number = stoul(d_matched);
+                d_number = A2x(d_matched);
                 return Parser::NUMBER;
             }
         }
