--- base/compiler/Parse/lex/sml.lex.orig	2018-05-28 17:11:09 UTC
+++ base/compiler/Parse/lex/sml.lex
@@ -114,7 +114,7 @@ hexnum={xdigit}("_"*{xdigit})*;
 frac="."{num};
 exp=[eE](~?){num};
 real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
-bad_escape="\\"[\000-\008\011\012\014-\031 !#$%&'()*+,\-./:;<=>?@A-Z\[\]_`c-eg-mo-qsuw-z{}|~\127];
+bad_escape=\\(]|[-\000-\008\011\012\014-\031 !#$%&'()*+,./:;<=>?@A-Z\[_`c-eg-mo-qsuw-z{}|~\127]);
 
 %%
 
