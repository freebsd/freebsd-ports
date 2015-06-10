--- scanner/lex.cc.orig	2015-05-17 14:35:38 UTC
+++ scanner/lex.cc
@@ -2698,7 +2698,7 @@ try
         {
 #line 194 "lexer"
             {
-                d_number = stoul(d_matched);
+                d_number = A2x(d_matched);
                 return Parser::NUMBER;
             }
         }
