--- src/main.cpp.orig	2025-05-16 09:03:24 UTC
+++ src/main.cpp
@@ -96,7 +96,7 @@ void loadTranslations(QApplication &app, QTranslator &
         missingTranslation = false;
     }
 
-    if (missingTranslation && language != "en")
+    if (missingTranslation && language != "en" && language != "C"  )
     {
         QMessageBox::warning(nullptr, "KLog",
                              QString("No translation files for your language were found. KLog will be shown in English.\n")
