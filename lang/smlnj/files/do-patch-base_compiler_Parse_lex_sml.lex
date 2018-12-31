--- base/compiler/Parse/lex/sml.lex.orig	2018-05-28 19:11:09.000000000 +0200
+++ base/compiler/Parse/lex/sml.lex	2018-07-27 17:58:18.054955000 +0200
@@ -114,7 +114,7 @@
 frac="."{num};
 exp=[eE](~?){num};
 real=(~?)(({num}{frac}?{exp})|({num}{frac}{exp}?));
-bad_escape="\\"[\000-\008\011\012\014-\031 !#$%&'()*+,\-./:;<=>?@A-Z\[\]_`c-eg-mo-qsuw-z{}|~\127];
+bad_escape=\\(]|[-\000-\008\011\012\014-\031 !#$%&'()*+,./:;<=>?@A-Z\[_`c-eg-mo-qsuw-z{}|~\127]);
 
 %%
 
