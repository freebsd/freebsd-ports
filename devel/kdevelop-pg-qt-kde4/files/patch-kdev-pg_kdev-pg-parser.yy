--- kdev-pg/kdev-pg-parser.yy.orig	2012-01-27 21:40:18 UTC
+++ kdev-pg/kdev-pg-parser.yy
@@ -309,7 +309,7 @@ opt_lexer_action
     | T_CONTINUE {
         r = "\nlxCONTINUE;\n";
       }
-    | /* empty */ { r = "\nlxSKIP\n" }
+    | /* empty */ { r = "\nlxSKIP\n"; }
     ;
 
 regexp
