--- spellchecker.h.orig	2016-09-16 19:56:10 UTC
+++ spellchecker.h
@@ -100,7 +100,7 @@ public:
   QString user_dir;
   QString lng;
 
-  char *encoding;
+  const char *encoding;
   QString dict_dir;
   
   CHunspellChecker (const QString &lang, const QString &path = "", const QString &user_path = "");
