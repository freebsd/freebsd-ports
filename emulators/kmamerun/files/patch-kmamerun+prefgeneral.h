--- kmamerun/prefgeneral.h.orig	Wed Feb 26 21:05:12 2003
+++ kmamerun/prefgeneral.h	Wed Feb 26 21:05:37 2003
@@ -29,7 +29,7 @@
 
 struct general_prefs {
     QString rompath;
-    QString spooldir;
+    QString hiscoredir;
     int cheat;
     // local data
     QString mamecmd;
@@ -58,8 +58,8 @@
 	//Generated area. DO NOT EDIT!!!(begin)
 	QLabel *labelMamedir;
 	QLineEdit *inputMamedir;
-	QLabel *labelSpooldir;
-	QLineEdit *inputSpooldir;
+	QLabel *labelHiscoredir;
+	QLineEdit *inputHiscoredir;
 	QLabel *labelMamecmd;
 	QLineEdit *inputMamecmd;
 	QLabel *labelLogdir;
