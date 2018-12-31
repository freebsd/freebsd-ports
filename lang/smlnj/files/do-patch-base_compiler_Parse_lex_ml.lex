--- base/compiler/Parse/lex/ml.lex.orig	2018-05-28 19:11:09.000000000 +0200
+++ base/compiler/Parse/lex/ml.lex	2018-07-27 17:27:36.367358000 +0200
@@ -66,7 +66,7 @@
 real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
 xdigit=[0-9a-fA-F];
 hexnum={xdigit}+;
-bad_escape="\\"[\000-\008\011\012\014-\031 !#$%&'()*+,\-./:;<=>?@A-Z\[\]_`c-eg-mo-qsuw-z{}|~\127];
+bad_escape=\\(]|[-\000-\008\011\012\014-\031 !#$%&'()*+,./:;<=>?@A-Z\[_`c-eg-mo-qsuw-z{}|~\127]);
 
 %%
