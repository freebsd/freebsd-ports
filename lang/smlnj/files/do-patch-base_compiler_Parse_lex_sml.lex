--- base/compiler/Parse/lex/sml.lex.orig	2024-10-25 16:47:18 UTC
+++ base/compiler/Parse/lex/sml.lex
@@ -114,7 +114,7 @@ real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
 frac="."{num};
 exp=[eE](~?){num};
 real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
-bad_escape="\\"[\000-\008\011\012\014-\031 !#$%&'()*+,\-./:;<=>?@A-Z\[\]_`c-eg-mo-qsuw-z{}|~\127];
+bad_escape=\\(]|[-\000-\008\011\012\014-\031 !#$%&'()*+,./:;<=>?@A-Z\[_`c-eg-mo-qsuw-z{}|~\127]);
 
 %%
 
