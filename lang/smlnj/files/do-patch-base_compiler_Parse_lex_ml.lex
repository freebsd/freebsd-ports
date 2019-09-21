--- base/compiler/Parse/lex/ml.lex.orig	2018-05-28 17:11:09 UTC
+++ base/compiler/Parse/lex/ml.lex
@@ -66,7 +66,7 @@ exp=[eE](~?){num};
 real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
 xdigit=[0-9a-fA-F];
 hexnum={xdigit}+;
-bad_escape="\\"[\000-\008\011\012\014-\031 !#$%&'()*+,\-./:;<=>?@A-Z\[\]_`c-eg-mo-qsuw-z{}|~\127];
+bad_escape=\\(]|[-\000-\008\011\012\014-\031 !#$%&'()*+,./:;<=>?@A-Z\[_`c-eg-mo-qsuw-z{}|~\127]);
 
 %%
 <INITIAL>{ws}	=> (continue());
