--- ./src/language.c.orig	2007-07-16 01:05:23.000000000 +0300
+++ ./src/language.c	2008-05-06 10:20:22.000000000 +0300
@@ -335,6 +335,9 @@
 {
   if (spoken == NULL) {
     char *lang = getenv("LANG");
+    if(!lang)
+           return TranslationEnglish[label].locale;
+
     if (strcmp(lang, "de") == 0 || strcmp(lang, "de_DE") == 0)
       spoken = TranslationGerman;
     else if (strcmp(lang, "es") == 0 || strcmp(lang, "es_ES") == 0)
