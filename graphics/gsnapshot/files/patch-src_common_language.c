--- src/common/language.c.orig	2007-07-28 15:49:17.000000000 +0200
+++ src/common/language.c	2010-01-13 21:07:22.000000000 +0100
@@ -335,6 +335,9 @@
 {
   if (spoken == NULL) {
     char *lang = getenv("LANG");
+    if(!lang)
+      return TranslationEnglish[label].locale;
+
     if (strcmp(lang, "de") == 0 || strcmp(lang, "de_DE") == 0)
       spoken = TranslationGerman;
     else if (strcmp(lang, "es") == 0 || strcmp(lang, "es_ES") == 0)
